#include <bits/stdc++.h>
using namespace std;
const int int_max = 1 << 22;
long long tree[2 * int_max], lazy_tag[2 * int_max];
long long n, temp_n;
int main() {
  int n, store[1000], n_, flag = 0;
  bool visit[1000] = {0};
  cin >> n;
  n_ = n;
  for (int z = 0; z < n; z++) cin >> store[z];
  for (int z = n - 1; z >= 0; z--) {
    if (!visit[store[z]])
      visit[store[z]] = 1;
    else {
      n_--;
      store[z] = -1;
    }
  }
  cout << n_ << endl;
  for (int z = 0; z < n; z++) {
    if (store[z] != -1) {
      flag++;
      if (flag == n_) {
        cout << store[z] << endl;
        break;
      }
      cout << store[z] << " ";
    }
  }
  return 0;
}
