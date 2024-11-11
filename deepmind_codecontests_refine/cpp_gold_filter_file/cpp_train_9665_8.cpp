#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,c=0;
  cin>>n;
  map<int,int> m;
  for(int i=0;i<n;i++){
    cin>>a;
    m[a]++;
  }
  for(auto t:m){
    if(t.second%2==1) c++;
  }
  cout<<c;
}