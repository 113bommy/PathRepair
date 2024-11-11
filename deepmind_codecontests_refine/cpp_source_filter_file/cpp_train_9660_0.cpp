#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int size = str.size();
	vector<int> v(size+1);
	for(int i = 0; i < size; i++) {
		if(str[i] == '<') {
			v[i+1] = max(v[i+1], v[i] + 1);
		}
	}
	for(int i = size - 1; i >= 0; i--) {
		if(str[i] == '>') {
			v[i] = max(v[i], v[i] + 1);
		}
	}
	long long ans = 0;
	for(int i = 0; i <= n; i++) ans += v[i];
	cout << ans << endl;
	return 0;
}