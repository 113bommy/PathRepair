#include <bits/stdc++.h>
using namespace std;
int diff(int h1, int m1, int h2, int m2) { return h2 * 60 + m2 - h1 * 60 - m1; }
void showTime(int time) { cout << time / 60 << " " << time % 60 << endl; }
int execute() {
  int n, s;
  cin >> n >> s;
  int h[n], m[n], i, time[n];
  for (i = 0; i < n; i++) cin >> h[i] >> m[i];
  if (h[0] * 60 + m[0] >= s + 1) {
    cout << "0 0\n";
    return 0;
  }
  for (i = 0; i < n - 1; i++) {
    time[i] = diff(h[i], m[i], h[i + 1], m[i + 1]);
    if ((time[i] - 2) >= s * 2) {
      showTime(h[i] * 60 + m[i] + s + 1);
      return 0;
    }
  }
  showTime(h[n - 1] * 60 + m[n - 1] + s + 1);
  return 0;
}
char mtest = false;
unsigned short TE = 1;
int main() {
  ios_base::sync_with_stdio(false);
  if (mtest) cin >> TE;
  while (TE--) execute();
  return 0;
}
