#include<bits/stdc++.h>
using namespace std;
 
#define reps(i,j,n) for(int i = (j) ; i < (int)(n) ; ++i)    
#define rep(i,n) reps(i,0,n)  
#define each(it,c) for(__typeof (c).begin() it = (c).begin(); it != (c).end(); it++)    
typedef pair< int , int > Pi;  
typedef pair< int , Pi > Pii;
typedef long long int64;  
const int INF = 1 << 30;  
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1,T2>& a){ return is>>a.first>>a.second; }  
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1,T2>& a){ return os<<a.first<<" "<<a.second; }  
template<typename T> istream& operator>>(istream& is, vector< T >& vc){ rep(i,sz(vc)) is >> vc[i]; return is;}  
template<typename T> ostream& operator<<(ostream& os, vector< T >& vc){ rep(i,sz(vc)) os << vc[i] << endl; return os; }

int N;
Pi data[300000];

int calc(int value) { //value:許容匹数
  int64 sum = 0; //放出量の合計
  priority_queue< Pi, vector< Pi >, greater< Pi > > que; //許容量が小さい順
  for(int i = 0; i < N; i++){
    que.push( Pi( data[i].second, data[i].first));
    sum += data[i].first;
    // sum / que.size() を摂取する → sum / que.size() <= que.top()
    while(!que.empty() && sum > (int64)valueue.size() * que.top().first){
      sum -= que.top().second;
      que.pop();
    }
    if(que.size() >= value) return true;
  }
  return false;
}

int Binary_Search( int row, int high) {
  int mid = (row + high + 1) >> 1;
  if(row == high)    return(row);
  else if(calc(mid)) return(Binary_Search( mid, high));
  else               return(Binary_Search( row, mid - 1));
}

int main() {

  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d %d", &data[i].first, &data[i].second);
  }
  sort( data, data + N);
  cout << Binary_Search( 0, N) << endl;
}