#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
  cin >>n;
  set<string> a[n];
  string b[n];
  bool c=false;
  for (int i=0;i<n;i++){
  	cin >> b[i];
    a.insert(b[i]);
  }
  if (a.size()==n){
  	c=true;
    for (int i=0;i<n-1;i++){
    	if (b[i].back()==b[i+1].front()) c=false;
    }
  }
  if (c) cout <<"Yes"<<endl;
  else cout <<"No"<<endl;
}