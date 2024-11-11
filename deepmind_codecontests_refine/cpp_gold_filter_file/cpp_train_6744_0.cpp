#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i < n-1; i++){
   int t;cin>>t;
    arr[t-1]++;
  }
  for(int i : arr) cout<<i<<"\n";
}
