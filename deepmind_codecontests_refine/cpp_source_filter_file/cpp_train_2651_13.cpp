#include <bits/stdc++.h>
const int MAXN = 1E6 + 10;
struct cmp {
  int d;
  cmp(int _d) { d = _d; }
  bool operator()(const int& a, const int& b) const { return a % d < b % d; }
};
std::vector<int> inv(const std::vector<int>& a) {
  int n = a.size();
  std::vector<int> c;
  c.resize(n);
  for (int i = 0; i < n; ++i) {
    c[a[i]] = i;
  }
  return c;
}
std::vector<int> init(int n) {
  std::vector<int> c;
  c.resize(n);
  for (int i = 0; i < n; ++i) {
    c[i] = i;
  }
  return c;
}
std::vector<int> operator*(const std::vector<int>& a,
                           const std::vector<int>& b) {
  int n = a.size();
  std::vector<int> c;
  c.resize(n);
  for (int i = 0; i < n; ++i) {
    c[i] = b[a[i]];
  }
  return c;
}
std::vector<int> pow(std::vector<int> a, int b) {
  std::vector<int> c = init(a.size());
  while (b) {
    if (b & 1) c = c * a;
    a = a * a;
    b >>= 1;
  }
  return c;
}
std::vector<int> dSort(int n, int k, int d) {
  std::vector<int> c = init(n);
  int now = 0;
  for (int i = 0; i < d; ++i) {
    for (int j = i; j < k; j += d) {
      c[j] = now++;
    }
  }
  return c;
}
std::vector<int> b;
std::vector<int> trans(int n, int k, int d) {
  std::vector<int> a = dSort(n, k, d);
  std::vector<int> c = init(n);
  std::rotate(c.begin(), c.begin() + (n - k), c.end());
  return a * pow(b * a, n - k) * c;
}
char s[MAXN], v[MAXN];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  int m;
  scanf("%d", &m);
  {
    b = init(n);
    std::rotate(b.begin(), b.end() - 1, b.end());
  }
  std::vector<int> ans = init(n);
  for (int i = 0; i < m; ++i) {
    int k, d;
    scanf("%d%d", &k, &d);
    ans = ans * trans(n, k, d);
    for (int i = 0; i < n; ++i) {
      v[ans[i]] = s[i];
    }
    v[n + 1] = '\0';
    printf("%s", v);
  }
  return 0;
}
