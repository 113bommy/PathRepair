#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long int f(int lo, int hi, int prev) {
  long long int res = 0;
  int tl = -1;
  int min = 2000000000;
  int c = 0;
  for (int i = lo; i <= hi; i++) {
    if (v[i] < min) min = v[i];
  }
  for (int i = lo; i <= hi; i++) {
    if (v[i] > min && tl == -1)
      tl = i;
    else if (v[i] == min) {
      c++;
      if (tl != -1) {
        long long int r = f(tl, i - 1, min);
        if (r > 0) res += r;
        tl = -1;
      }
    } else if (i == hi && tl != -1) {
      long long int r = f(tl, i, min);
      if (r > 0) res += r;
    }
  }
  res += c;
  res -= min - prev;
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  int res = n;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    v.push_back(a);
  }
  long long int r = f(0, v.size() - 1, 0);
  if (r > 0) res = res - r;
  printf("%d\n", res);
  return 0;
}
