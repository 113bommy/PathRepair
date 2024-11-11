#include<bits/stdc++.h>
using namespace std;

string s;
vector<string>v={"SUN","MON","TUE","WED","THU","FRI","SAT"};

int main(){
	cin>>s;
	
	for(int i=0;i<7;i++){
		if(v[i]==s){
			cout<<7-i<<'\n';
			return 0;
		}
	}
}