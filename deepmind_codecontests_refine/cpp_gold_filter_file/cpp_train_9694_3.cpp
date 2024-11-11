#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int a[400005], b[400005], c[400005], d[400005], e[1000005];
int main() {
  int n, n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  cin >> n;
  long long sum = 0;
  while (n--) {
    string s;
    int m;
    cin >> s >> m;
    if (s == "00") a[n1++] = m;
    if (s == "01") b[n2++] = m;
    if (s == "10") c[n3++] = m;
    if (s == "11") d[n4++] = m;
  }
  for (int i = 0; i < n4; i++) sum += d[i];
  sort(b, b + n2, cmp);
  sort(c, c + n3, cmp);
  if (n2 > n3) {
    for (int i = 0; i < n3; i++) sum += (c[i] + b[i]);
    for (int j = 0; j < n1; j++) {
      e[j] = a[j];
    }
    for (int k = n1; k < n1 + n2 - n3; k++) {
      e[k] = b[k - n1 + n3];
    }
    sort(e, e + n1 + n2 - n3, cmp);
    for (int i = 0; i < n4; i++) sum += e[i];
  } else {
    for (int i = 0; i < n2; i++) sum += (b[i] + c[i]);
    for (int j = 0; j < n1; j++) {
      e[j] = a[j];
    }
    for (int k = n1; k < n1 + n3 - n2; k++) {
      e[k] = c[k - n1 + n2];
    }
    sort(e, e + n1 + n3 - n2, cmp);
    for (int i = 0; i < n4; i++) sum += e[i];
  }
  cout << sum << endl;
  return 0;
}
