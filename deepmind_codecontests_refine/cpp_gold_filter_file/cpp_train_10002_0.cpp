#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
set<int>st;
int main() {
	int q;
	cin >> q;
	while (q--) {
		int Q, k;
		cin >> Q >> k;
		if (Q == 0) {
			st.insert(k);
			cout << st.size() << endl;
		}
		else {
			cout << st.count(k) << endl;
		}
	}
	return 0;
}
