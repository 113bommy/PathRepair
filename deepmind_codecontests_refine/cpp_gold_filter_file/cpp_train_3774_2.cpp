#include <bits/stdc++.h>
using namespace std;
using dou = long double;
string yes = "yes";
string Yes = "Yes";
string YES = "YES";
string no = "no";
string No = "No";
string NO = "NO";
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
long long ceil(long long a, long long b) { return ((a + b - 1) / b); }
const int INF = 1000000000;
const long long INF64 = 9223372036854775807ll;
const long long MOD = 1000000007ll;
const dou pi = 3.141592653589793;
int n, m;
bool bo = 0;
string anan;
void dfs(std::vector<bool> b, std::vector<std::vector<std::set<int>>>& s, int t,
         string ans) {
  std::vector<bool> d(b);
  if (ans.size() == m) {
    bo = 1;
    anan = ans;
    return;
  }
  for (int i = 0; i < (int)(26); i++) {
    if (s[t][i].size() != 0) {
      bool hoge = 0;
      for (int j = 0; j < (int)(n); j++) {
        if (s[t][i].find(j) != s[t][i].end())
          continue;
        else {
          if (d[j]) {
            hoge = 1;
            break;
          } else
            d[j] = 1;
        }
      }
      if (hoge) {
        for (int i = 0; i < (int)(d.size()); i++) d[i] = b[i];
        continue;
      }
      string du;
      du.push_back(i + 'a');
      dfs(d, s, t + 1, ans + du);
      for (int i = 0; i < (int)(d.size()); i++) d[i] = b[i];
    }
  }
}
int main() {
  int qq;
  std::cin >> qq;
  for (int qqq = 0; qqq < (int)(qq); qqq++) {
    std::cin >> n >> m;
    bo = 0;
    anan = "";
    std::vector<string> a(n);
    for (int i = 0; i < (int)(n); i++) std::cin >> a[i];
    std::vector<bool> b(n, 0);
    if (m == 1) {
      std::cout << 'a' << std::endl;
      continue;
    }
    vector<vector<std::set<int>>> s(m, vector<std::set<int>>(26));
    for (int i = 0; i < (int)(n); i++) {
      for (int j = 0; j < (int)(m); j++) {
        s[j][a[i][j] - 'a'].insert(i);
      }
    }
    dfs(b, s, 0, "");
    if (bo)
      std::cout << anan << std::endl;
    else
      std::cout << -1 << std::endl;
  }
}
