#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, tmp = 1, res = 0;
	cin >> N;
	for (int i = 0, a; i < N; i++) {
		cin >> a;
		if (a > tmp) {
			res += (a - 1) / tmp;
			tmp = max(tmp, 2);
		}
		else if(a == tmp)
			tmp++;
	}
	cout << res << endl;
	return 0;
}
