#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,i,b,sum=0
  long long ans1=0;
  cin>>n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin>>a[i];
    a[i]-=i;
    sum+=a[i];
  }
  sort(a,a+n);
  /*if(n%2==0)b=(a[n/2]+a[(n/2)-1])/2;
  else */b=a[(n-1)/2];
  for (i = 0; i < n; i++) {
    ans1+=abs(a[i]-b);
  }
  cout<<ans1<<endl;
  return 0;
}
