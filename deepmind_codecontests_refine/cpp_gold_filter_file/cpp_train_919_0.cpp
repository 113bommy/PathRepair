#include<iostream>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

int main(){
  ll n,k,a[100010],s[100010],m[100010],t=0;
  cin>>n>>k;
  fr(i,n) cin>>a[i];
  fr(i,n){
    s[i+1]=s[i]+a[i];
    m[i+1]=m[i]+max(a[i],(ll)0);
  }
  fr(i,n-k+1){
    t=max(t,m[i]+m[n]-m[i+k]+max((ll)0,s[i+k]-s[i]));
  }
  cout<<t<<endl;
}