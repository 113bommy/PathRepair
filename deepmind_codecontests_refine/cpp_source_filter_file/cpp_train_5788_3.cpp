#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
T expo(T base, T e, T mod) {
  T res = 1;
  while (e > 0) {
    if (e & 1) res = res * base % mod;
    base = base * base % mod;
    e >>= 1;
  }
  return res;
}
template <typename T, typename second>
T expo(T b, second e) {
  if (e <= 1) return e == 0 ? 1 : b;
  return (e & 1) == 0 ? expo((b * b), e >> 1) : (b * expo((b * b), e >> 1));
}
template <typename T, typename second>
T modinv(T a, second mod) {
  return expo(a, mod - 2, mod);
}
template <class T, class second>
std::ostream &operator<<(std::ostream &os, const std::pair<T, second> &t) {
  os << "(" << t.first << ", " << t.second << ")";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &t) {
  os << "[";
  for (__typeof(t.begin()) it = t.begin(); it != t.end(); it++) {
    if (it != t.begin()) os << ", ";
    os << *it;
  }
  os << "]";
  return os;
}
template <typename T>
void in(T &x) {
  T c = getchar();
  while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
  bool neg = false;
  if (c == '-') neg = true;
  x = 0;
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x * 10) + (c - 48);
  if (neg) x = -x;
}
const int MAXN = 2e5 + 3;
int n, k;
vector<int> adj[MAXN];
int cnt_down[MAXN][5];
int cnt_up[MAXN][5];
long long sum = 0, res = 0;
void compute_down(int r, int p) {
  for (auto &elem : adj[r]) {
    if (elem != p) {
      compute_down(elem, r);
      for (int i = 0; i < k; i++) {
        cnt_down[r][(i + 1) % k] += cnt_down[elem][i];
      }
    }
  }
  cnt_down[r][0]++;
}
void compute_up(int r, int p) {
  int temp[5] = {0};
  for (auto &elem : adj[r]) {
    if (elem != p) {
      for (int i = 0; i < k; i++) {
        temp[i] += cnt_down[elem][i];
      }
    }
  }
  for (auto &elem : adj[r]) {
    if (elem != p) {
      for (int i = 0; i < k; i++) {
        cnt_up[elem][(i + 1) % k] += cnt_up[r][i];
        temp[i] -= cnt_down[elem][i];
      }
      for (int i = 0; i < k; i++) {
        cnt_up[elem][(i + 2) % k] += temp[i];
      }
      cnt_up[elem][1 % k]++;
      for (int i = 0; i < k; i++) temp[i] += cnt_down[elem][i];
      compute_up(elem, r);
    }
  }
}
void dfs(int r, int p, int d) {
  sum += (d + k - 1) / k;
  for (auto &elem : adj[r]) {
    if (elem != p) {
      dfs(elem, r, d + 1);
    }
  }
}
void go(int r, int p, long long sum) {
  res += sum;
  for (auto &elem : adj[r]) {
    if (elem != p) {
      long long nsum = sum + cnt_up[elem][1] - cnt_down[elem][0];
      go(elem, r, nsum);
    }
  }
}
int main() {
  int a, b;
  in(n), in(k);
  for (int i = 1; i < n; i++) {
    in(a), in(b);
    adj[a].push_back(b), adj[b].push_back(a);
  }
  compute_down(1, 0);
  compute_up(1, 0);
  dfs(1, 0, 0);
  go(1, 0, sum);
  printf("%I64d\n", res / 2);
  return 0;
}
