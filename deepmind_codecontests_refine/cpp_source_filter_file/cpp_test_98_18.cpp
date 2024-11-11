#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < 2 * t; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    unordered_map<char, long long> mp;
    for (long long i = 0; i < s1.length(); i++) {
      mp[s1[i]] = i + 1;
    }
    long long count = 0;
    for (long long j = 1; j < s2.length(); j++) {
      count += abs(mp[s2[j]] - mp[s2[j - 1]]);
    }
    cout << count << endl;
  }
}
