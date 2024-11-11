#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
int v[1000100];
int v2[1000100];
int n;
long long int S = 0;
int antes = 0, depois = 0;
int mapa[1000100];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    v[i]--;
    S += abs(v[i] - i);
    if (i < n - 1) {
      antes += ((v[i] - i) > 0);
      depois += ((v[i] - i) <= 0);
    }
  }
  for (int i = 0; i < n; i++) {
    int s = v[i] - i;
    if (s < 0) s += n;
    v2[i] = s;
    mapa[v2[i]]++;
  }
  int j = n - 1;
  long long int r = S;
  int idx = 0;
  for (int i = 1; i < n; i++) {
    S = S - abs(v[j] - n + 1);
    S = S + v[j] - antes + depois;
    antes = antes - mapa[i] + 1 - (v[j] == 0) - (v[j - 1] - n + 1 >= 0);
    depois = depois + mapa[i] - 1 + (v[j] == 0) - (v[j - 1] - n + 1 < 0);
    j--;
    if (S < r) {
      r = S;
      idx = i;
    }
  }
  cout << r << " " << idx << endl;
  return 0;
}
