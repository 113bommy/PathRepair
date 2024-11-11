#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,n;
  cin>>k>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int ans = a[n-1]-a[0];
  for(int i=1;i<n;i++){
  	ans = min(ans, k-(a[i]-a[i-1]);
  }
   cout<<ans<<endl;
}