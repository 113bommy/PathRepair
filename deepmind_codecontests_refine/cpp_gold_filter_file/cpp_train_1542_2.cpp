#include<iostream>
using namespace std;
#define ll long long
int main(){
  ll N,M=0;
  ll i,j;
  ll tmp;
  cin >> N;
  ll a[N+1],b[N+1];
  for(i=1;i<=N;i++){
    cin >> a[i];
    b[i]=0;
  }
  for(i=N;i>0;i--){
    tmp=0;
    j=i;
    while(j<=N){
      tmp=(tmp+b[j])%2;
      j+=i;
    }
    b[i]=(tmp+a[i])%2;
    if(b[i]==1)M++;
  }
  cout << M << endl;
  for(i=1;i<=N;i++){
    if(b[i]==1)cout << i << " ";
  }
  return 0;
}