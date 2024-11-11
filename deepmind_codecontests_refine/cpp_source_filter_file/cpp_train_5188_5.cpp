#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int  n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		char s;
		cin >> s;
		if(s=='y'){
			cout << "Four" << endl;
			return;
		}
	}
	
	cout << "Three" << endl;
}