#include<iostream>
using namespace std;
#define ll long long
int main(){
  ll mx=0;
  ll tmp=0;
  ll H1,H2;
  ll N;
  cin >> N >> H1;
  for(ll i=0;i<N-1;i++){
    cin >> H2;
    if(H1>=H2)tmp++;else tmp=0;
    mx=max(tmp,mx);
    H1=H2;
  }
  cout << mx;
  return 0;
}