#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int mas[MAXN];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> mas[i];
  int ans = -1;
  for (int j = 0; j <= 30; j++) {
    int tmp = 1 << j;
    int cnt = 0;
    int ind = -1;
    for (int k = 0; k < n; k++)
      if (tmp & mas[k]) {
        ind = k;
        cnt++;
      }
    if (cnt == 1) {
      ans = ind;
      break;
    }
  }
  if (ans == -1) {
    for (int j = 0; j < n; j++) cout << mas[j] << " ";
  } else {
    cout << mas[ans];
    for (int j = 0; j < n; j++)
      if (j != ans) cout << " " << mas[j];
  }
  return 0;
}
