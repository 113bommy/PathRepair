#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 200005;
struct gauss {
  vector<int> vet;
  int ans;
  gauss() { ans = 0; }
  gauss(int val) {
    if (val) vet.push_back(val), ans = val;
  }
  bool add(int val) {
    int sig = 20;
    for (int i = 0; i < (int)vet.size(); i++) {
      while (sig >= 0 && !(vet[i] & (1 << sig))) sig--;
      if (sig < 0) break;
      if (val & (1 << sig)) val ^= vet[i];
    }
    if (!val) return false;
    sig = 20;
    while (sig >= 0 && !(val & (1 << sig))) sig--;
    if (sig < 0) return true;
    for (int &x : vet)
      if (x & (1 << sig)) x ^= val, ans ^= val;
    vet.push_back(val);
    ans ^= val;
    for (int i = (int)vet.size() - 2; i >= 0 && vet[i] < vet[i + 1]; i--) {
      swap(vet[i], vet[i + 1]);
    }
    return true;
  }
};
int v[N];
int pxor[N];
gauss g;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if (i) pxor[i] = pxor[i - 1];
    pxor[i] ^= v[i];
    g.add(pxor[i]);
  }
  if (pxor[n - 1] == 0) {
    printf("-1\n");
  } else {
    printf("%d\n", g.vet.size());
  }
  return 0;
}
