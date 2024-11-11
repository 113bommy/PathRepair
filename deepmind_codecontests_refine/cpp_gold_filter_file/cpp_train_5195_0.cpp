#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
 
using namespace std;
 
#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10
#define MOD 1000000007
 
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;
 
deque<pi>vec, a, b, c;
int N, M, P, Q, R;
 
int cnt(int p, int q, int r){
  if(p > r) return 0;
  if(r >= q) return q-p+1;
  return r-p+1;
}
 
int countR(int p, int q, int r){
  int n = 1, vp, res = 0;
  for(vp=0;vp<vec.size();vp++){
    int f = vec[vp].F, l = vec[vp].S;
    int c = l-f+1;
    if(n <= p){
      if(n+c < p){
      }
      else if(n + c > q){
    res += cnt(f+p-n, f+q-n, r);
      }else{
    res += cnt(f+p-n, l, r);
      }
      n += c;
    }else if(n <= q){
      if(n+c<=q){
    res += cnt(f, l, r);
      }else{
    res += cnt(f, f+q-n, r);
      }
      n += c;
    }
  }
  return res;
}
 
 
int main(){
  while(1){
    cin >> N;
    if(!N) break;
    cin >> M >> P >> Q >> R;
    vec.clear();
    vec.push_back(MP(1,N));
    int x, y;
    rep(i, M){
      cin >> x >> y;
      a.clear(); b.clear();
      int p=1;
      while(p<=x){
    int f = vec[0].F, s = vec[0].S;
    if(p+s-f<=x){
      a.push_back(MP(f,s));
      p += s-f+1;
      vec.pop_front();
    }else if(p+s-f>x){
      a.push_back(MP(f, f+x-p));
      vec[0].F = f+x-p+1;
      p = x+1;
    }
      }
      while(p<=y){
    int f = vec[0].F, s = vec[0].S;
    if(p+s-f<=y){
      b.push_back(MP(f, s));
      p += s-f+1;
      vec.pop_front();
    }else if(p+s-f>y){
      b.push_back(MP(f, f+y-p));
      vec[0].F = f+y-p+1;
      p = y+1;
    }
      }
 
      vec.insert(vec.end(), b.begin(), b.end());
      vec.insert(vec.end(), a.begin(), a.end());
 
    }
 
 
    /*    rep(i, vec.size()){
      for(int j=vec[i].F;j<=vec[i].S;j++) cout << j << endl;;
      }*/
    cout << countR(P, Q, R) << endl;
  }
}
