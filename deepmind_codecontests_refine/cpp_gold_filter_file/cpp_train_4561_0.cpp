#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	string S;
	cin >> S;
	int ss = S.size();
	ll aj = 0, ans = 0;
	for (int i = 0;i < ss - 2;i++) {
		if (S[i] == 'A')
			aj++;
		else
			aj = 0;
		if (S[i] == 'A'&&S[i + 1] == 'B'&&S[i + 2] == 'C') {
			ans += aj;
			S[i + 2] = 'A';
			aj--;
			i++;
		}
	}
	cout << ans << endl;
}