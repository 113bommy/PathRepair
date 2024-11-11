#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int cou[N], n, high, best, color[N], ans[N];
int main(int argc, const char* argv[]) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> color[i];
    color[i]--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cou[j] = 0;
    }
    high = 0;
    best = -1;
    for (int j = i; j < n; j++) {
      cou[color[j]]++;
      int myCount = cou[color[j]];
      if (myCount > high || (myCount == high && color[j] < color[i])) {
        high = myCount;
        best = color[j];
      }
      ans[best]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}
