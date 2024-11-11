#include <bits/stdc++.h>
using namespace std;
int main(){
long long int n,ans=0;
  cin >> n;
  long long int a[3*n];
  for (int i=0;i<3*n;i++)cin >> a[i];
  sort(a,a+3*n);
  reverse (a,a+3*n);
  for (int i=0;i<n;i++)ans+=a[1+2*i];
  cout << ans <<endl;
}
