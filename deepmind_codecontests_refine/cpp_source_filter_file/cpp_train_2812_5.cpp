include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, q, S[10000], T, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	sort(S, S + n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> T;
		if (binary_search(S, S + n, T))
			res++;
	}
	cout << res << endl;
	return 0;
}