#include <bits/stdc++.h>
using namespace std;
int n, k;
int ai[300007], bi[100007];
void solve() {
  cin >> n;
  map<int, int> last, gap;
  int a;
  for (int i = 1; i <= n; i++) {
    a = i;
    if (gap[a] < i - last[a]) {
      gap[a] = i - last[a];
    }
    last[a] = i;
  }
  for (map<int, int>::iterator i = last.begin(); i != last.end(); i++) {
    if (gap[i->first] < n + 1 - i->second) {
      gap[i->first] = n + 1 - i->second;
    }
  }
  int pre = n + 1;
  fill(ai, ai + n + 7, -1);
  for (map<int, int>::iterator i = gap.begin(); i != gap.end(); i++) {
    if (i->second < pre) {
      for (int j = i->second; j < pre; j++) {
        ai[j] = i->first;
      }
      pre = i->second;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ai[i] << ' ';
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
