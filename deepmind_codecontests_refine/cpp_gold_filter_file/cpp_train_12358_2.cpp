#include <bits/stdc++.h>
using namespace std;
vector<int> clouds[2];
bool test(int s, int e, int w) { return (e - s) * (long long)w > abs(e + s); }
int main() {
  int n, l, w;
  cin >> n >> l >> w;
  for (int i = 0; i < n; i++) {
    int s, v;
    cin >> s >> v;
    clouds[v < 0].push_back(s);
  }
  for (int i = 0; i < 2; i++) {
    sort(clouds[i].begin(), clouds[i].end());
  }
  long long ans = 0;
  int lidx = 0;
  for (int x : clouds[1]) {
    while (1) {
      if (test(clouds[0][lidx], x + l, w) && lidx < clouds[0].size()) {
        lidx++;
      } else
        break;
    }
    ans += lidx;
  }
  cout << ans << endl;
  return 0;
}
