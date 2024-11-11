#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

string s, t;
int a[26];
int b[26];

int main() {
	cin >> s >> t;
	rep(i, s.size())a[s[i] - 'a']++;
	rep(i, s.size())b[t[i] - 'a']++;
	sort(a, a + 26);
	sort(b, b + 26);
	rep(i, 26) {
		if (a[i] != b[i]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	getchar();
	getchar();
	return 0;
}