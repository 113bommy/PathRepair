#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = 0;
  int numb = 0;
  if (n <= 3) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int val = (n - 1) / i + 1;
    int res = n - i - val + 1;
    if (res > numb) {
      numb = res;
      k = i;
    }
  }
  vector<bool> bad(n);
  for (int i = 0; i < n; i += k) {
    bad[i] = 1;
  }
  vector<bool> used(n);
  while (1) {
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      if (!bad[i] && !used[i]) arr.push_back(i);
    }
    if (arr.size() < k) {
      cout << 0 << endl;
      return 0;
    }
    cout << k << " ";
    for (int i = 0; i < k; i++) {
      cout << arr[i] + 1 << " ";
      used[arr[i]] = 1;
    }
    cout << endl;
    int ind;
    cin >> ind;
    ind--;
    for (int j = 0; j < k; j++) {
      used[(j + ind) % n] = 0;
    }
  }
}
