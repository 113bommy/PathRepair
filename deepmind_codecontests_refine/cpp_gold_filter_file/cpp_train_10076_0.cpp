#include<bits/stdc++.h>
using namespace std;

int main(){
  
 int n;
 cin>>n;
  
 int a;
 int ans = 0;
  
 int mini = INT_MAX;
  
 for(int i=0;i<n;i++){
  cin>>a;
  if(a<=mini)
    ans++;
  mini = min(mini,a);
 }
  
 cout<<ans;
  
}
