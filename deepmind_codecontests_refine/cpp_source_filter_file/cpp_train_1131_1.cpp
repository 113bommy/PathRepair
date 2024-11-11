#include<bits/stdc++.h>
using namespace std;

void strReplace(string& str, const string& from, const string& to){
	string::size_type pos = 0;
	while(pos = str.find(from, pos), pos != string::npos){
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
}

int main(){
	cin >> n;
	cin.clear();
	cin.ignore();
	for(int i = 0; i < n; i++){
		string s;
		getline(cin, s);
		strReplace(s, "Hoshino","Hoshina");
		cout << s << endl;
	}
}