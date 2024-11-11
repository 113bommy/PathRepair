#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
inline bool REMIN(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool REMAX(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
int toint(const string &s) {
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
string tostring(int number) {
  stringstream ss;
  ss << number;
  return ss.str();
}
const int INF = INT_MAX;
const int NMAX = 1000004;
const long long MOD = 1000000007;
const long double PI = 2 * acos(0);
int T, N, M, A, B, K;
int a, b;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> A >> B >> K;
  cin >> s;
  for (int(i) = int(0); (i) <= int(s.length() - 1); ++(i)) {
    if (s[i] == '1') {
      for (int(j) = int(i - 1); (j) >= int(max(0, i - B + 1)); --(j))
        if (s[j] == '1')
          break;
        else
          s[j] = '1';
    }
  }
  for (int(i) = int(s.length() - 1); (i) >= int(s.length() - B + 1); --(i))
    s[i] = 1;
  set<int> ava;
  for (int(i) = int(0); (i) <= int(s.length() - 1); ++(i)) {
    if (s[i] == '0') ava.insert(i + 1);
  }
  set<int> ans;
  auto use = *ava.begin();
  while (1) {
    auto nex = ava.lower_bound(use + B);
    nex--;
    ans.insert(*nex);
    nex++;
    if (nex == ava.end()) break;
    use = *nex;
  }
  int mar = ((int)(ans.size())) + 1 - A;
  auto pr = ans.begin();
  cout << mar << "\n";
  while (mar--) {
    cout << *pr << ' ';
    ans.erase(pr);
    pr = ans.begin();
  }
  return 0;
}
