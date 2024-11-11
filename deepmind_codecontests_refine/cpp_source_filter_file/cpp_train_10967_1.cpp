#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, val;
  cin >> n >> k;
  vector<int> vec;
  int counter = 0;
  for (int i = 0; i <= n * 2; i++) {
    cin >> val;
    vec.push_back(val);
  }
  for (int i = 1; i <= n * 2; i++) {
    if (i % 2 != 0) {
      int swap = vec[i];
      swap = swap - 1;
      if (swap != vec[i - 1] && swap != vec[i]) {
        vec[i] = swap;
        counter++;
      }
    }
    if (counter == k) break;
  }
  for (int i = 0; i <= n * 2; i++) {
    cout << vec[i] << " ";
  }
  return 0;
}
