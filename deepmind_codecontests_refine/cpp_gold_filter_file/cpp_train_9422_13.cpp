#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ar(n);
  vector<int> pos(n);
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    pos[tmp - 1] = i;
  }
  int cnt = 1, mx = 1;
  for (int i = 1; i < n; i++) {
    if (pos[i - 1] < pos[i]) {
      cnt++;
      mx = max(mx, cnt);
    } else
      cnt = 1;
  }
  cout << n - mx << endl;
}
