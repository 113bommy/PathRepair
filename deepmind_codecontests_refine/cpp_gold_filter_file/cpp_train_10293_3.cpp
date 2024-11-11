#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
  int n; cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  
  int ans = 1e9;
  for(int k=-100;k<=100;k++){
		int cost = 0;
    	for(int i=0;i<n;i++) cost += (k-arr[i])*(k-arr[i]);
    	ans = min(ans,cost);
  }
  cout<<ans;
  
 return 0; 
}