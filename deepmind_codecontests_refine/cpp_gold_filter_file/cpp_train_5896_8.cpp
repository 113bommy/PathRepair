#include <bits/stdc++.h>
using namespace std;
const int MX = (1 << 20);
int arr[MX];
vector<int> v[MX];
int n, done[MX];
int main() {
  int ans = 0;
  cin >> n;
  for (int j = 1; j <= n; j++) {
    int x;
    scanf("%d", &x);
    arr[j] = x;
  }
  for (int j = n; j >= 0; j--) {
    v[arr[j]].push_back(j);
  }
  for (int j = 0; j <= n; j++) {
    if (done[j]) continue;
    int x = j;
    done[j] = 1;
    v[arr[j]].pop_back();
    ++ans;
    while (1) {
      if (v[x].empty()) break;
      int nxt = v[x].back();
      v[x].pop_back();
      done[nxt] = 1;
      x = nxt;
    }
  }
  cout << ans << endl;
}
