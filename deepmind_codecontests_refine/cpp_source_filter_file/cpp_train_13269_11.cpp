#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int nums[100005];
  int numes[1000005];
  int count[100005];
  for (int i = 0; i < 100005; ++i) {
    nums[i] = 0;
    numes[i] = 0;
    count[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    ++numes[k - 1];
    count[i] = numes[k - 1];
  }
  for (int i = 0; i < n - 1; ++i) {
    if (numes[i + 1] > numes[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  cout << numes[0] << endl;
  for (int i = 0; i < n; ++i) cout << count[i] << ' ';
  cout << endl;
}
