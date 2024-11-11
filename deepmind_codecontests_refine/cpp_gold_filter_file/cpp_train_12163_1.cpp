#include <bits/stdc++.h>
using namespace std;
int n,a[100007],s;
int main(){
  cin >> n;
  for(int i = 1; i<=n; i++) cin >> a[i];
  for(int i = 0; i<=n; i++) s+=abs(a[i]-a[i+1]);
  for(int i = 1; i<=n; i++)
    cout<<s+abs(a[i-1]-a[i+1])-abs(a[i]-a[i+1])-abs(a[i]-a[i-1])<<endl;
}
