#include <iostream>
#include <string>

using namespace std;

int main() {
	string s; cin >> s;
	long long k; cin >> k;
	int tmp = 0;
	while (s[tmp] == '1') tmp++;
	if (tmp < k) cout << s[tmp] << endl;
	else cout << 1 << endl;

	return 0;
}