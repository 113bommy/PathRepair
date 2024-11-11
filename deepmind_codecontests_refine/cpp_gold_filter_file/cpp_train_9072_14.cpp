#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, r[N], c[N], res = 1;
vector<pair<int, int> > v;
void in() { cin >> n; }
void process() {
  r[1] = 1, c[1] = 1;
  for (int i = 2; i <= n; i++) {
    int tmp = -1e9;
    for (int j = i - 1; j >= 1; j--) {
      tmp = max(tmp, (i - j) + c[j] + r[j]);
    }
    r[i] = tmp / 2, c[i] = tmp - r[i], res = max(res, max(r[i], c[i]));
  }
  cout << res << endl;
  for (int i = 1; i <= n; i++) cout << r[i] << ' ' << c[i] << endl;
}
int main() {
  in();
  process();
}
