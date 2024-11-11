#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  ll sum[n];
  sum[0]=a[0];
  for(int i=1;i<n;i++){
    sum[i]=sum[i-1]+a[i];
  }
  int x=0;
  for(int i=0;i<n-1;i++){
    if(2*sum[i]<a[i+1]){
      x=i;
    }
  }
  cout << n-x-1 << endl
}