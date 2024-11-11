#include<bits/stdc++.h>
using namespace std;

map<char,int> ma;
char c;
int main(){
	for(int i = 0; i < 4; i++){
	cin >> c;
	ma[c]++;
	}
	for(auto u : ma){
		if(u.second != 2){cout << "No\n"; return 0;}
	}
	cout << "Yes\n";
}
