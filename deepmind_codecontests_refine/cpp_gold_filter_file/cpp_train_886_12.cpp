#include <bits/stdc++.h>
using namespace std;
static const int N = 5010;
int c[N];
int s[N];
int r[N];
bool vece(int a, int b) {
  if (s[a] != s[b]) return (s[a] > s[b]);
  return (a < b);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%i", &c[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) s[j] = 0;
    int m = 0;
    for (int j = i; j < n; j++) {
      s[c[j]]++;
      if (vece(c[j], c[m])) m = j;
      r[c[m]]++;
    }
  }
  for (int i = 1; i <= n; i++) printf("%i ", r[i]);
  printf("\n");
  return 0;
}
