#include <bits/stdc++.h>
using namespace std;
const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
int toint(const string &s) {
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
long long int mpow(long long int a, long long int n) {
  long long int ret = 1;
  long long int b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % 1000000000;
    b = (b * b) % 1000000000;
    n >>= 1;
  }
  return (long long int)ret;
}
struct cmp {
  bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first < b.first.first)
      return true;
    else if (a.first.first == b.first.first)
      return a.first.second < b.first.second;
    return false;
  }
};
int p[100005] = {0}, val[100005] = {0};
map<int, int> hashm;
vector<int> v;
int find(int x) {
  if (x == p[x]) return x;
  p[x] = find(p[x]);
  return p[x];
}
void union1(int c, int p1) { p[find(c)] = find(p1); }
int main() {
  int tc;
  tc = 1;
  int i, n, m, a, b, num, j;
  while (tc--) {
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    for (i = 1; i <= n; i++) {
      scanf("%d", &num);
      hashm[num] = i;
      v.push_back(num);
      p[i] = i;
    }
    for (i = 1; i <= n; i++) {
      num = v[i - 1];
      if (hashm.find(a - num) != hashm.end()) {
        union1(hashm[num], hashm[a - num]);
        val[hashm[num]] |= 1;
      }
      if (hashm.find(b - num) != hashm.end()) {
        union1(hashm[num], hashm[b - num]);
        val[hashm[num]] |= 2;
      }
    }
    for (i = 1; i <= n; i++) {
      num = v[i - 1];
      j = find(hashm[num]);
      val[j] &= val[hashm[num]];
      val[hashm[num]] = val[j];
      if (val[j] == 0) break;
    }
    if (i <= n)
      printf("NO\n");
    else {
      printf("YES\n");
      for (i = 1; i <= n; i++) {
        j = find(hashm[v[i - 1]]);
        if (val[j] == 1)
          printf("0 ");
        else
          printf("1 ");
      }
      printf("\n");
    }
  }
  return 0;
}
