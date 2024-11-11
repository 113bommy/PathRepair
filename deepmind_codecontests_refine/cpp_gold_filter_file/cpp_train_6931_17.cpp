#include <bits/stdc++.h>
using namespace std;
int spf[100002];
void SPF() {
  spf[0] = spf[1] = -1;
  for (int i = 2; i < 100002; ++i) spf[i] = i;
  for (int i = 2; i * i < 100002; ++i) {
    if (spf[i] == i) {
      for (int j = i; j * i < 100002; ++j)
        if (spf[i * j] == i * j) spf[i * j] = i;
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  SPF();
  int n;
  cin >> n;
  cout << (n + 1 > 3 ? 2 : 1) << "\n";
  for (int i = 2; i < n + 2; ++i) cout << (spf[i] == i ? 1 : 2) << " ";
  return 0;
}
