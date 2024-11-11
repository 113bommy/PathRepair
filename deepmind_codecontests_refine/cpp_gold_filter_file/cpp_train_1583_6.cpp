#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<pair<int, int> > primes;
  bitset<1001> bs;
  bs.set();
  for (int i = 2; i <= n; i++) {
    if (bs[i]) {
      for (int j = 2 * i; j <= n; j += i) bs[j] = 0;
      primes.push_back(pair<int, int>(n / i, i));
    }
  }
  sort(s.begin(), s.end());
  vector<pair<int, char> > group;
  int t = 1;
  char c = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      t++;
    else {
      group.push_back(make_pair(t, c));
      t = 1;
      c = s[i];
    }
  }
  group.push_back(make_pair(t, c));
  sort(group.begin(), group.end());
  sort(primes.begin(), primes.end());
  for (int i = 0; i < n; i++) s[i] = '0';
  int it = (int)group.size() - 1, cnt;
  for (int i = (int)primes.size() - 1; i >= 0; i--) {
    if (it == -1) {
      printf("NO");
      return 0;
    }
    cnt = 0;
    for (int j = primes[i].second - 1; j < n; j += primes[i].second)
      if (s[j] == '0') cnt++;
    if (cnt > group[it].first) {
      it--;
      i++;
      continue;
    }
    for (int j = primes[i].second - 1; j < n; j += primes[i].second) {
      if (s[j] != '0') {
        if (s[j] == group[it].second)
          continue;
        else {
          printf("NO");
          return 0;
        }
      }
      s[j] = group[it].second;
      group[it].first--;
    }
  }
  it = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      while (!group[it].first) it++;
      s[i] = group[it].second;
      group[it].first--;
    }
  }
  printf("YES\n");
  cout << s;
}
