#include <bits/stdc++.h>
using namespace std;
bool a[100];
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(k);
  for (int i = 0; i < k; i++) cin >> v[i], a[v[i]] = 1;
  for (int i = 0; i < k; i++) {
    int x = v[i];
    cout << x << " ";
    int j = 2;
    for (int z = 1; z <= k * n && j <= n; z++) {
      if (!a[z]) {
        j++;
        cout << z << " ";
        a[z] = 1;
      }
    }
    puts("");
  }
}
