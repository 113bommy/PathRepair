#include<iostream>
using namespace std;
#define ll long long
int main(){
  ll N;
  cin >> N;
  ll a[N];
  ll ans[N];
  ans[0]=0;
  ll tmp=-1;
  for(i=0;i<N;i++){
    cin >> a[i];
    ans[0]+=tmp*a[i];
    tmp*=-1;
  }
  for(i=0;i<N-1;i++){
    ans[i+1]=(a[i]-ans[i]/2)*2;
  }
  for(i=0;i<N;i++){
    cout << ans[i] <<" ";
  }
  return 0;
}