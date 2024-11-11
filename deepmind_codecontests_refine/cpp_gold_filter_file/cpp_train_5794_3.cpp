#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> answers;
  for (int i = 0; i < n; i++) {
    int val = min(i, k) + 1 + min(n - i - 1, k);
    if (a[i] == 0) {
      answers.push_back(val);
    } else {
      int right = min(n - i - 1, k);
      int left = min(i, k);
      int per = (i - left) - ((a[i] - 1) + min(k, n - (a[i] - 1) - 1)) - 1;
      int zn = per > 0 ? 0 : per;
      answers.push_back((left + right + 1 + answers[a[i] - 1]) + zn);
    }
  }
  for (int i = 0; i < n; i++) cout << answers[i] << " ";
  return 0;
}
