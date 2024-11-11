#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long k;
  cin >> k;
  long long n = s.length();
  long long i;
  long long a[26];
  for (i = 0; i < 26; i++) {
    a[i] = 0;
  }
  vector<pair<long long, char>> v;
  for (i = 0; i < n; i++) {
    long long x = s[i] - 'a';
    a[x]++;
  }
  for (i = 0; i < 26; i++) {
    v.push_back(make_pair(a[i], char('a' + i)));
  }
  sort(v.begin(), v.end());
  set<char> s1;
  long long sum = 0;
  for (i = 0; i < 26; i++) {
    if (v[i].first != 0 && k > v[i].first) {
      s1.insert(v[i].second);
      k = k - v[i].first;
    }
    if (k < v[i].first) {
      break;
    }
  }
  string s2 = "";
  for (i = 0; i < n; i++) {
    if (s1.find(s[i]) == s1.end()) {
      s2.push_back(s[i]);
    }
  }
  long long c;
  set<char> q;
  if (s2 == "") {
    c = 0;
  } else {
    for (i = 0; i < s2.length(); i++) {
      q.insert(s2[i]);
    }
    c = q.size();
  }
  cout << c << endl;
  cout << s2;
}
