#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, ans="Good";
	cin >> s;
	for (int i=0;i<3;i++){
		if (s.at(i)==s.at(i+1)){
			ans ="Bad";
		}
	}
	cout << ans << endl;
}