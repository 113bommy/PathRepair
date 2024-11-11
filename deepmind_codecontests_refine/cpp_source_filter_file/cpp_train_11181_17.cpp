#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
using namespace std;
string s1, s2;
long long n, w;
char a, b;
long long dist[27][27];
char cheapest[505];
class BStringProblem {
 public:
  void solve(std::istream& in, std::ostream& out) {
    in >> s1 >> s2;
    if (s1.length() != s2.length()) {
      out << -1 << "\n";
      return;
    }
    in >> n;
    for (long long i = (0); i < (26); i++)
      for (long long j = (0); j < (26); j++) dist[i][j] = 10000000000;
    for (long long i = (0); i < (26); i++) dist[i][i] = 0;
    for (long long i = (0); i < (n); i++) {
      in >> a >> b >> w;
      dist[a - 'a'][b - 'a'] = min(dist[a - 'a'][b - 'a'], w);
    }
    for (long long k = (0); k < (26); k++)
      for (long long i = (0); i < (26); i++)
        for (long long j = (0); j < (26); j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    long long ans = 0;
    long long tempans = 0;
    long long tempchar = 0;
    for (long long i = (0); i < (s1.length()); i++) {
      tempans = 10000000000;
      for (long long j = (0); j < (26); j++)
        if (dist[s1[i] - 'a'][j] + dist[s2[i] - 'a'][j] < tempans) {
          tempans = dist[s1[i] - 'a'][j] + dist[s2[i] - 'a'][j];
          tempchar = j;
        }
      if (tempans >= 10000000000) {
        out << -1 << "\n";
        return;
      }
      ans += tempans;
      cheapest[i] = 'a' + tempchar;
    }
    out << ans << "\n";
    for (long long i = (0); i < (s1.length()); i++) out << cheapest[i];
    out << "\n";
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  BStringProblem solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
