#include <bits/stdc++.h>
using namespace std;
void READ(string INPUT = "NO", string OUTPUT = "NO") {
  if (INPUT != "NO") freopen(INPUT.c_str(), "r", stdin);
  if (OUTPUT != "NO") freopen(OUTPUT.c_str(), "w", stdout);
}
int frq[100001];
int n, t;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    frq[t]++;
  }
  int mx = 1;
  for (int i = 2; i <= 100000 / 2; i++) {
    int curm = frq[i];
    for (int j = i * 2; j < 100001; j += i) {
      curm += frq[j];
    }
    mx = max(curm, mx);
  }
  cout << mx << "\n";
  return 0;
}
