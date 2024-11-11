#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

vector<i64> A(202020,1e18),B(202020,1e18);
vector<i64> Ab(512,1e18),Bb(512,1e18);
vector<int> lazy(512,0);
const int Interval = 512;

int N;

const i64 INF = 1e18;

void LAZY(int s){
  if(lazy[s] == 0) return;
  if(lazy[s] == 1){Ab[s] = Bb[s];}
  if(lazy[s] == -1){Bb[s] = Ab[s];}
  for(int i = s * Interval;i < (s + 1) * Interval;i++){
    if(lazy[s] == 1){A[i] = B[i];}
    if(lazy[s] == -1){B[i] = A[i];}
  }
  lazy[s] = 0;
}

int main(){
  cin >> N;
  rep(i,0,N - 1) cin >> A[i];
  rep(i,0,N - 1) cin >> B[i];
  rep(i,0,N - 1) Ab[i/ Interval] = min(Ab[i / Interval] , A[i]);
  rep(i,0,N - 1) Bb[i/ Interval] = min(Bb[i / Interval] , B[i]);

  int Q;
  cin >> Q;
  rep(q,0,Q - 1){
    int x,y,z;
    cin >> x >> y >> z;
    if(x == 1){
      y--;
      LAZY(y / Interval);
      A[y] = z;
      int start = y - y % Interval;
      int end = start + Interval;
      end = min(end,N);
      Ab[y / Interval] = INF;
      for(int i = start;i < end;i++){
        Ab[y / Interval] = min(Ab[y / Interval],A[i]);
      }
      Bb[y / Interval] = INF;
      for(int i = start;i < end;i++){
        Bb[y / Interval] = min(Bb[y / Interval],B[i]);
      }
    }
    if(x == 2){
      y--;
      LAZY(y / Interval);
      B[y] = z;
      int start = y - y % Interval;
      int end = start + Interval;
      end = min(end,N);
      Ab[y / Interval] = INF;
      for(int i = start;i < end;i++){
        Ab[y / Interval] = min(Ab[y / Interval],A[i]);
      }
      Bb[y / Interval] = INF;
      for(int i = start;i < end;i++){
        Bb[y / Interval] = min(Bb[y / Interval],B[i]);
      }
    }
    if(x == 3){
      y--;
      i64 ans = A[y];
      int before = -1;
      while(y < z){
        if(y % Interval == 0 && y + Interval <= z){
          if(lazy[y / Interval] != 1) ans = min(ans , Ab[y / Interval]);
          else ans = min(ans , Bb[y / Interval]);
          y += Interval;
        }
        else{
          LAZY(y / Interval);
          if(before != y / Interval){
              int start = y - y % Interval;
      int end = start + Interval;
      end = min(end,N);
      Ab[y / Interval] = INF;
      for(int i = start;i < end;i++){
        Ab[y / Interval] = min(Ab[y / Interval],A[i]);
      }
      Bb[y / Interval] = INF;
      for(int i = start;i < end;i++){
        Bb[y / Interval] = min(Bb[y / Interval],B[i]);
      }
          }
          before = y / Interval;
          ans = min(ans , A[y]);
          y++;
        }
      }
      cout << ans << endl;
    }
    if(x == 4){
      y--;
      i64 ans = B[y];
      int before = -1;
      while(y < z){
        if(y % Interval == 0 && y + Interval <= z){
         if(lazy[y / Interval] != -1) ans = min(ans , Bb[y / Interval]);
          else ans = min(ans , Ab[y / Interval]);
          y += Interval;
        }
        else{
          LAZY(y / Interval);
          if(before != y / Interval){
              int start = y - y % Interval;
      int end = start + Interval;
      end = min(end,N);
      Ab[y / Interval] = INF;
      for(int i = start;i < end;i++){
        Ab[y / Interval] = min(Ab[y / Interval],A[i]);
      }
      Bb[y / Interval] = INF;
      for(int i = start;i < end;i++){
        Bb[y / Interval] = min(Bb[y / Interval],B[i]);
      }
          }
          before = y / Interval;
          ans = min(ans , B[y]);
          y++;
        }
      }
      cout << ans << endl;
    }
    if(x == 5){
      for(int i = 0;i < N / Interval + 1;i++){
        if(lazy[i] != -1) lazy[i] = 1;
      }
    }
    if(x == 6){
      for(int i = 0;i < N / Interval + 1;i++){
        if(lazy[i] != 1) lazy[i] = -1;
      }
    }
  }
}

