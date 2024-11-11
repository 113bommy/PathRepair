#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  map<char, long long int> mp;
  for (long long int i = 0; i < n; i++) {
    mp[s[i]]++;
    mp[t[i]]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second % 2) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  vector<pair<long long int, long long int> > v;
  int count = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      int j = i + 1;
      while (t[i] != t[j] && j < n) j++;
      if (j == n) {
        j = i + 1;
        while (t[i] != s[j] && j < n) j++;
        if (j == n) {
          cout << "No\n";
          return;
        } else {
          v.push_back(make_pair(j + 1, j + 1));
          v.push_back(make_pair(i + 1, j + 1));
          count += 2;
          swap(s[j], t[j]);
          swap(s[i], t[j]);
        }
      } else {
        v.push_back(make_pair(i + 1, j + 1));
        count++;
        swap(s[i], t[j]);
      }
    }
  }
  cout << count;
  cout << "\n";
  for (auto it : v) cout << it.first << " " << it.second << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) fun();
  return 0;
}
