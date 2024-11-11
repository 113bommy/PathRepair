#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  int n, a[5010], dom[5010];
  cin >> n;
  for (int i = 0; (i) < (n); ++i) cin >> a[i];
  for (int i = 0; (i) < (n); ++i) {
    int num[5010];
    for (int j = 0; (j) < (5010); ++j) num[j] = 0;
    int domi = a[i];
    dom[a[i]]++;
    num[a[i]]++;
    for (int j = i + 1; j < n; j++) {
      num[a[j]]++;
      if (num[a[j]] > num[domi] || (num[a[j]] == num[domi] && a[j] < domi)) {
        dom[a[j]]++;
        domi = a[j];
      } else
        dom[domi]++;
    }
  }
  for (int i = 1; i < n + 1; i++) cout << dom[i] << ((i == n) ? '\n' : ' ');
  return 0;
}
