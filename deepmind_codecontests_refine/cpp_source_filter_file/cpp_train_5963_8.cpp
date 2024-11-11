#include <bits/stdc++.h>
using namespace std;
int n;
int a[333][333];
bool bad;
int pos[333], ans[333], p[333][333], b[333];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      a[i][j]--;
      p[i][a[i][j]] = j;
    }
    b[i] = n - 1;
  }
  for (int i = 0; i < n; i++) {
    int B;
    cin >> B;
    B--;
    pos[B] = i;
    ans[i] = -1;
  }
  int best = -1;
  int secbest = -1;
  int bestp = 111111;
  for (int i = 0; i < n; i++) {
    if (pos[i] < bestp) {
      secbest = best;
      bestp = pos[i];
      best = i;
    } else if (secbest == -1 || pos[i] < pos[secbest]) {
      secbest = i;
    }
    for (int j = 0; j <= i; j++)
      if (p[j][best] < b[j] && best != j) {
        b[j] = p[j][best];
        ans[j] = i;
      } else if (best == j && secbest != -1 && secbest != j &&
                 p[j][secbest] < b[j]) {
        b[j] = p[j][secbest];
        ans[j] = i;
      }
  }
  for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
  cout << endl;
  return 0;
}
