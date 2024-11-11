#include <bits/stdc++.h>
using namespace std;
template <typename C>
auto test(C* x) -> decltype(cerr << *x, 0LL);
template <typename C>
char test(...);
template <typename C>
struct itr {
  C begin, end;
};
template <typename C>
itr<C> get_range(C b, C e) {
  return itr<C>{b, e};
}
struct debug {
  template <typename T>
  debug& operator<<(const T&) {
    return *this;
  }
};
template <typename T>
string _ARR_(T* arr, int sz) {
  string ret = "{ " + to_string(arr[0]);
  for (int i = 1; i < sz; i++) ret += " , " + to_string(arr[i]);
  ret += " }";
  return ret;
}
const int INF = 1e9 + 7;
bool cmp[27][27];
int n, m;
int letters[27], found[27];
vector<string> words;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  words.resize(n * m);
  for (int i = 0; i < n; ++i) {
    int id;
    cin >> id;
    id *= m;
    for (int j = 0; j < m; ++j) {
      cin >> words[id];
      for (char c : words[id]) letters[(c - 'a')] = 1;
      ++id;
    }
  }
  for (int i = 1; i < n * m; ++i) {
    string s1 = words[i - 1], s2 = words[i];
    s1 += ' ';
    s2 += ' ';
    int p = 0;
    while (min(s1.size(), s2.size()) > p) {
      if (s1[p] != s2[p]) {
        if (s2[p] == ' ') {
          cout << "IMPOSSIBLE\n";
          return 0;
        }
        if (s1[p] == ' ') {
          break;
        }
        cmp[s1[p] - 'a'][s2[p] - 'a'] = 1;
        break;
      }
      p++;
    }
  }
  int sz = 0;
  for (int i = 0; i < 27; ++i) sz += letters[i];
  for (int i = 0; i < 27; ++i) {
    for (int j = 0; j < 27; ++j) {
      for (int k = 0; k < 27; ++k) {
        if (cmp[j][i] && cmp[i][k]) cmp[j][k] = 1;
      }
    }
  }
  for (int i = 0; i < 27; ++i) {
    for (int j = i + 1; j < 27; ++j) {
      if (cmp[i][j] && cmp[j][i]) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  }
  int mn;
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j < 27; ++j)
      if (letters[j] && !found[j]) mn = j;
    for (int j = 0; j < 27; ++j) {
      if (!found[j] && letters[j] && cmp[j][mn]) mn = j;
    }
    cout << char('a' + mn);
    found[mn] = 1;
  }
  cout << '\n';
  return 0;
}
