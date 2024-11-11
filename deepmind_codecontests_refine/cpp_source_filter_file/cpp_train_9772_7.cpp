#include<bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    map<char,bool>Map;
	for (char c : a) {
		Map[c] = true;
	}
	if ((Map['N'] == Map['S']) && (Map['E'] == Map['W'])) {
        cout << "Yes" << endl;
    }
	else {
        cout << "No" << endl;
    }
}