#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;
  
  vector<int> v(n),temp(n);
  
  for(int i = 0; i < n ; i++) { cin>>v[i]; temp=v[i];}
  
  sort(v.begin(), v.end());
  
  for(int i =0 ; i < n; i++) {
    if(temp[i] != v[n-1]) cout<<v[n-1]<<endl;
    else cout<< v[n-2]<<endl;
  }
}