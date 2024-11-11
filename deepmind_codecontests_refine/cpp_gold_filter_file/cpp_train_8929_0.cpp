#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int>seen;
  	int mx = 0;
  	int n; cin>>n;
  	for(int i = 0; i < n; i++){
    	string s;
      	cin>>s;
      	seen[s]++;
      	if(seen[s] > mx)mx = seen[s];
    }
  	for(auto& a : seen){
    	if(a.second == mx)cout<<a.first<<"\n";
    }
	return 0;
}