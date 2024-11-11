#include<bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int ans=1000;
	for (int i = 0; i < S.size() - 2; i++) {
		int diff;
		diff = 753 - stoi(S.substr(i, 3));
		ans = min(ans, abs(diff));
	}
	cout << ans << endl;
	erturn 0;
}