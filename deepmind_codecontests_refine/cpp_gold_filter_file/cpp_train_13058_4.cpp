#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  int n, t, c, Start, End, ans = 0;
  cin >> n >> t >> c;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  Start = End = 0;
  while (Start < n) {
    bool ok = false;
    while (End < n) {
      if (v[End] > t) {
        Start = End + 1;
        End = End + 1;
        continue;
      }
      if (End - Start + 1 == c) {
        ok = true;
        break;
      }
      End++;
    }
    ok ? ans++ : ok;
    Start++;
  }
  cout << ans;
}
