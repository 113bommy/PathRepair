#include "bits/stdc++.h"

using namespace std;
int main()
{
	int cnt = 0;
	int ans = 0;
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'A' || a[i] == 'G' || a[i] == 'C' || a[i] == 'T')
			cnt++;
		else
			cnt = 0;
		ans = max(cnt, ans);
	}
	cout << ans << endl;
}

