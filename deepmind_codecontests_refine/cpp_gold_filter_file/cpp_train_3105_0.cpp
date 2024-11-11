#include <bits/stdc++.h>
using namespace std;
int n,a[101],kol,ans=0;
int main(){
	cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++){
      kol++;
      if (i==n || a[i+1]!=a[i]) {ans+=kol/2; kol=0; }
    }
    cout<<ans;
}
