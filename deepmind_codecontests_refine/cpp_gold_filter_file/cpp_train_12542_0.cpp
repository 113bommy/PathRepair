#include <bits/stdc++.h>
using namespace std;
long long stoll(string target) {
  stringstream s;
  s << target;
  long long w;
  s >> w;
  return w;
}
int stoi(string target) {
  stringstream s;
  s << target;
  int w;
  s >> w;
  return w;
}
string itos(int i) {
  stringstream s;
  s << i;
  return s.str();
}
string lltos(long long i) {
  stringstream s;
  s << i;
  return s.str();
}
int a[300001];
int main() {
  ios::sync_with_stdio(false);
  bool ok = true, final = false;
  int i, j, k, n, m;
  int t;
  int br = 0, pom, mom, g, f;
  long long odgovor = 0;
  memset((a), (0), sizeof((a)));
  cin >> n;
  for (i = 1; i <= (int)(n); i++) {
    cin >> a[i];
  }
  int x = 0, y = 0;
  f = 0;
  g = 0;
  int pamti = -1;
  sort(a + 1, a + n + 1);
  pamti = n + 1;
  while (true) {
    f = 0;
    g = 0;
    x = 0;
    y = 0;
    ok = false;
    for (i = pamti - 2; i >= 1; i--) {
      if (a[i] == a[i + 1]) {
        f = a[i];
        pamti = i;
        ok = true;
        break;
      } else if (a[i] == a[i + 1] - 1) {
        f = a[i];
        pamti = i;
        ok = true;
        break;
      }
    }
    if (!ok) {
      break;
    }
    for (j = pamti - 2; j >= 1; j--) {
      if (a[j] == a[j + 1]) {
        x = a[j];
        y = a[j + 1];
        pamti = j;
        ok = true;
        break;
      } else if (a[j] == a[j + 1] - 1) {
        x = a[j];
        y = a[j];
        pamti = j;
        ok = true;
        break;
      }
    }
    if (ok)
      odgovor = (long long)(odgovor + (long long)((long long)f * (long long)x));
    if (!ok) break;
  }
  cout << odgovor;
  return 0;
}
