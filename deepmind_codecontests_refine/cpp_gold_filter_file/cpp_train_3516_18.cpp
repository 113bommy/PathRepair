#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  long long total = 0;
  for(int i=0; i<n; i++) total^=arr[i];
  for(int i=0; i<n; i++) cout<<(total^arr[i])<<" ";
}