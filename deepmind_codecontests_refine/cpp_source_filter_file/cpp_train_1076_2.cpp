#include <bits/stdc++.h>
const int N = 200005;
using namespace std;
map<int, list<int>> mp;
int ar[N], n;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    mp[ar[i]].push_back(i);
  }
  ar[n + 1] = -1;
  int st = 0;
  for (int i = 1; i <= n; i++) {
    auto &d = mp[ar[i]];
    d.pop_front();
    for (auto j : d) {
      int a = i, b = j;
      do {
        a++;
        b++;
      } while (a < j && ar[a] == ar[b]);
      if (a == j) {
        i = j - 1;
        st = j;
      }
    }
  }
  cout << n - st + 1 << endl;
  for (int i = st; i <= n; i++) cout << ar[i] << ' ';
  return 0;
}
