#include <bits/stdc++.h>
using namespace std;
void scanint(long long int &x);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  scanint(n);
  long long int i = 0;
  long long int j = 0;
  long long int a[n];
  long long int b[n];
  for (i = 0; i < n; i++) scanint(a[i]);
  for (i = 0; i < n; i++) scanint(b[i]);
  if (a[j] == 0) j++;
  for (i = 0; i < n; i++) {
    if (a[j] == b[i]) {
      j = i;
      break;
    }
  }
  vector<long long int> v_a;
  vector<long long int> v_b;
  for (i = 0; i < n; i++) {
    if (a[i]) v_a.push_back(a[i]);
    if (b[j]) v_b.push_back(b[j]);
    j = (j + 1) % n;
  }
  for (i = 0; i < n - 1; i++)
    if (v_a[i] != v_b[i]) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
  return 0;
}
void scanint(long long int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
