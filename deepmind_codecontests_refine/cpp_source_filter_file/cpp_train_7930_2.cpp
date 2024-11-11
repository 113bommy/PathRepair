#include <bits/stdc++.h>
using namespace std;
void optimizeIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  optimizeIO();
  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = (int)(0); i < (int)(n); i++) cin >> v[i];
    map<int, int> maxind, minind;
    for (int i = (int)(0); i < (int)(n); i++) {
      minind[v[i]] = 2000000007;
      maxind[v[i]] = -1;
    }
    for (int i = (int)(0); i < (int)(n); i++) {
      maxind[v[i]] = max(maxind[v[i]], i);
      minind[v[i]] = min(minind[v[i]], i);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    vector<int> mem(n, 0);
    mem[n - 1] = 1;
    int temp = 0;
    for (int i = (int)(n - 1 - 1); i >= (int)(0); i--) {
      if (maxind[v[i]] < minind[v[i + 1]])
        mem[i] = mem[i + 1] + 1;
      else
        mem[i] = 1;
      temp = max(mem[i], temp);
    }
    cout << n - temp << endl;
  }
  return 0;
}
