#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    x <<= 24;
    arr[i] += x;
    getchar();
    cin >> x;
    x <<= 16;
    arr[i] += x;
    getchar();
    cin >> x;
    x <<= 8;
    arr[i] += x;
    getchar();
    cin >> x;
    arr[i] += x;
  }
  for (int i = 0; i < 32; ++i) {
    unsigned int t = 0;
    for (int j = 0; j <= i; ++j) {
      t += 1;
      t <<= 1;
    }
    t <<= (32 - i - 2);
    set<int> dict;
    for (int j = 0; j < n; ++j) {
      int c = arr[j] & t;
      dict.insert(c);
    }
    if (dict.size() == k) {
      cout << (t >> 24) << '.' << ((t >> 16) % 256) << '.' << ((t >> 8) % 256)
           << '.' << (t % 256);
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
