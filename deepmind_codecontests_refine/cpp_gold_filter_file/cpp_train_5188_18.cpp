#include<bits/stdc++.h>
using namespace std;

int n;
char s;

int main() {
	cin >> n;
	string ans = "Three";
	for(int i = 0; i < n; i++) {	
		cin >> s;
		if(s == 'Y')
			ans = "Four";
	}
	cout << ans;
}