#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
void print(vector<T>& v, bool spaced = true) {
  int n = v.size();
  string space = (spaced ? " " : "");
  for (int i = 0; i < n; ++i) {
    cout << v[i] << space;
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  map<char, int> m1;
  map<char, int> m2;
  for (int i = 0; i < n; ++i) {
    m1[s[i]]++;
    m2[t[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    if (find((t).begin(), (t).end(), s[i]) == t.end()) {
      cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (m1[s[i]] != m2[t[i]]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  vector<int> moves;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (t[i] == s[j]) {
        for (int k = j - 1; k > i - 1; --k) {
          swap(s[k], s[k + 1]);
          moves.push_back(k + 1);
        }
        break;
      }
    }
  }
  cout << moves.size() << '\n';
  print(moves);
  return 0;
}
