#include <bits/stdc++.h>
using namespace std;
long long a[50][50];
vector<int> get(long long n) {
  vector<int> v;
  int res = 0;
  while (n) {
    v.push_back(n % 2);
    res++;
    n /= 2;
  }
  return v;
}
int get_t(long long t) {
  int res = 1;
  while (t != 1) {
    if (t % 2) return -1;
    t /= 2;
    res++;
  }
  return res;
}
long long cnt(int n, int m) {
  if (n < m) return 0;
  if (m <= 0) return 0;
  n--, m--;
  long long res = 1;
  if (n - m < m) m = n - m;
  for (int i = n - m + 1; i <= n; i++) {
    res *= i;
    res /= (i - (n - m));
  }
  return res;
}
int main(void) {
  long long n, t;
  scanf("%lld%lld", &n, &t);
  n++;
  int cool = get_t(t);
  if (cool == -1) {
    printf("0\n");
    return 0;
  }
  vector<int> len_n = get(n);
  long long res = 0;
  for (int i = cool; i < len_n.size(); i++) {
    res += cnt(i, cool);
  }
  cool--;
  for (int i = len_n.size() - 2; i >= 0; i--) {
    if (len_n[i] == 1) {
      res += cnt(i + 1, cool + 1);
      cool--;
    }
  }
  if (cool == 0) res++;
  if (t == 1) res--;
  printf("%lld\n", res);
  return 0;
}
