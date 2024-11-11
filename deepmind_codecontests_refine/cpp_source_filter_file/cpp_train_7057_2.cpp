#include <bits/stdc++.h>

using namespace std;

long long solve(string s, long long k) {
	long long n = s.size();
  	if (count(s.begin(), s.end(), s[0]) == n)
      	return (n * k) / 2;
    }
	if (k == 1) {
    	long long ans = 0;
    	for(int i = 1; i < n; i++) {
          	if (s[i] == s[i - 1]) ans++, i++;
        }
      	return ans;
    }
	if (s[0] != s[n - 1])
      	return solve(s, 1) * k;
	int pref = 0;
	while (s[pref] == s[0]) pref++;
	string inside = s.substr(pref, n - pref) + s.substr(0, pref);
	return solve(s, 1) + solve(inside, k - 1);
}
int main() {
  	string s; long long k;
	cin >> s >> k;
	cout << solve(s, k);
}