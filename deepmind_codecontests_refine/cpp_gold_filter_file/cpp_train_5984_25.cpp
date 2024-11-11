#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long an = 0;
  map<char, long long> cnt;
  for (int i = 0; i < (int)s.size(); ++i) {
    cnt[s[i]]++;
  }
  for (auto cur : cnt) {
    an += cur.second * (cur.second - 1) / 2;
  }
  printf("%lld\n", an * 2 + (int)s.size());
}
