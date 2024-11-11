#include <bits/stdc++.h>
using namespace std;
int x, n, a[5005];
vector<int> power[2005];
vector<pair<int, int> > sell, taken;
char s[5];
bool cek(int p) {
  if (taken.empty()) return 1;
  for (int i = 0; i < taken.size(); i++)
    if (taken[i].first <= p && p <= taken[i].second) return 0;
  return 1;
}
bool cek2(int p, int q) {
  if (taken.empty()) return 1;
  for (int i = 0; i < taken.size(); i++) {
    int a = taken[i].first;
    int b = taken[i].second;
    if (a < p && p < b) return 0;
    if (a < q && q < b) return 0;
    if (p < a && a < q) return 0;
    if (p < b && b < q) return 0;
  }
  return 1;
}
void printout(vector<int> v) {
  if (v.empty())
    printf("0");
  else
    for (int i = 0; i < v.size(); i++) printf("%d", v[i]);
}
vector<int> add(vector<int> a, vector<int> b) {
  vector<int> c;
  int sisa = 0, i = a.size() - 1, j = b.size() - 1;
  while (1) {
    if (i < 0 || j < 0) break;
    int tmp = a[i] + b[j] + sisa;
    c.push_back(tmp % 10);
    sisa = tmp / 10;
    i--;
    j--;
  }
  while (i >= 0) {
    int tmp = a[i] + sisa;
    c.push_back(tmp % 10);
    sisa = tmp / 10;
    i--;
  }
  while (j >= 0) {
    int tmp = b[j] + sisa;
    c.push_back(tmp % 10);
    sisa = tmp / 10;
    j--;
  }
  if (sisa > 0) c.push_back(sisa);
  reverse(c.begin(), c.end());
  return c;
}
void por() {
  power[0].push_back(1);
  for (int x = 1; x <= 2000; x++) {
    vector<int> c;
    c = power[x - 1];
    int sisa = 0;
    int i = c.size() - 1;
    while (i >= 0) {
      int tmp = c[i] * 2 + sisa;
      power[x].push_back(tmp % 10);
      sisa = tmp / 10;
      i--;
    }
    if (sisa > 0) power[x].push_back(sisa);
    reverse(power[x].begin(), power[x].end());
  }
}
int main() {
  scanf("%d", &n);
  por();
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    scanf("%s %d", s, &a[i]);
    if (s[0] == 's') {
      sell.push_back(make_pair(a[i], i));
      a[i] = -1;
    }
  }
  sort(sell.begin(), sell.end());
  for (int i = sell.size() - 1; i >= 0; i--) {
    int x, p;
    x = sell[i].first;
    p = sell[i].second;
    int j;
    for (j = p - 1; j >= 1 && a[j] != -1; j--)
      if (a[j] == x) {
        for (; j <= p; j++) a[j] = -2;
        ans = add(ans, power[x]);
      }
  }
  printout(ans);
  printf("\n");
}
