#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> s(m), c(m);
	for(int i=0; i<m; i++) cin >> s[i] >> c[i];

	for(int i=0; i<1000; i++) {
		string x = to_string(i);
		if(x.size() == n) {
			bool valid=1;
			for(int j=0; j<m; j++) {
				if(x[s[j]-1] != ('0' + c[j]) valid=0;	
			}
			if(valid) {
				cout << i;
				return 0;
			}
		}
	}
	cout << -1;
    return 0;
}
