#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
	vector<string> s(3);
  	for(auto&& u:s)cin>>u;
    vector<int> t(3,0);
  //	rep(i,3)t[i]=s[i].size();
  
  int x=0;
  while(t[x]<s[x].size()){
  t[x]++;
  x=s[x][t[x]-1]-'a';  
  }
  cout<<"ABC"[x]<<endl;
  
}
