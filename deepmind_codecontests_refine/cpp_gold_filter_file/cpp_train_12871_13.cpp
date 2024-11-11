#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& n) {
  char ch;
  int sign = 1;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = -1;
  n = ch - '0';
  while (isdigit(ch = getchar())) n = n * 10 + ch - '0';
  n *= sign;
}
const int INF = 1e9;
int n, m, t;
struct node {
  long long first, second, z;
};
vector<node> ans;
bool isprime(long long first) {
  for (long long i = 2; i * i <= first; ++i)
    if (first % i == 0) return false;
  return first >= 2;
}
int main() {
  read(n), read(m);
  m -= n - 1;
  for (int i = (1); i <= (n - 2); ++i) ans.push_back((node){i, i + 1, 1});
  long long t = n - 2 + 1, del = 1;
  for (; !isprime(t); ++t, ++del)
    ;
  ans.push_back((node){n - 1, n, del});
  int i = 1, j = 3;
  while (m--) {
    ans.push_back((node){i, j, INF});
    j++;
    if (j > n) i++, j = i + 2;
  }
  cout << t << ' ' << t << endl;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first << ' ' << ans[i].second << ' ' << ans[i].z << endl;
  return 0;
}
