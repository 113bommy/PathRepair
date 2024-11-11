#include <bits/stdc++.h>
using namespace std;
string s;
bool is_prime(int a) {
  for (int i = 2; i < a; i++)
    if (a % i == 0) return false;
  return true;
}
vector<pair<int, char> > cnt;
vector<int> cc;
int main() {
  int n;
  cin >> s;
  if (s.size() == 1) {
    cout << "YES" << endl << s;
    return 0;
  }
  n = s.size();
  cc.resize(26);
  for (int i = 0; i < s.size(); i++) cc[s[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    if (cc[i] != 0) cnt.push_back(make_pair(cc[i], char(i + 'a')));
  s.assign(s.size(), '#');
  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());
  int pos = 1;
  while (pos < n) {
    if (cnt[0].first == '#') {
      cout << "NO";
      return 0;
    }
    cnt[0].first--;
    if (cnt[0].first < 0) {
      cout << "NO";
      return 0;
    }
    s[pos] = cnt[0].second;
    pos += 2;
  }
  for (int p = 3; p < n; ++p) {
    if (is_prime(p)) {
      sort(cnt.begin(), cnt.end());
      reverse(cnt.begin(), cnt.end());
      int pos = p - 1;
      char col = 0;
      while (pos < n) {
        if (s[pos] != '#') {
          col = s[pos];
          break;
        }
        pos += p;
      }
      int ind = 0;
      if (col != '#') {
        for (int i = 0; i < cnt.size(); ++i) {
          if (cnt[i].second == col) {
            ind = i;
            break;
          }
        }
      }
      pos = p - 1;
      while (pos < n) {
        if (s[pos] != '#' && s[pos] != cnt[ind].second) {
          cout << "NO";
          return 0;
        }
        if (s[pos] == '#') {
          if (cnt[ind].first == 0) {
            cout << "NO";
            return 0;
          }
          cnt[ind].first--;
        }
        s[pos] = cnt[ind].second;
        pos += p;
      }
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '#') {
      sort(cnt.begin(), cnt.end());
      reverse(cnt.begin(), cnt.end());
      s[i] = cnt[0].second;
      cnt[0].first--;
      if (cnt[0].first < 0) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES" << endl << s;
  return 0;
}
