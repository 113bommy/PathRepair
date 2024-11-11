#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin>>a[i];
  long long ans = 1000;
  for(int i = 0; i< n-1; i++){
   if(a[i] < a[i+1]){
    ans += (a[i+1]-a[i]) * (ans/a[i]); 
   }
  }
  cout<<ans<<endl;
 return 0; 
}