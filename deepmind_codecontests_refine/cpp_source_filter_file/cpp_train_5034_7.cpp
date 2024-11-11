#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v.push_back(t);
    sum += t;
  }
  if (sum % 3) {
    cout << 0 << endl;
    return 0;
  }
  int tgt = sum / 3;
  sum = 0;
  int cnt[100000];
  for (int i = 0; i < n; i++) {
    sum += v[i];
    cnt[i] = i ? cnt[i - 1] : 0;
    cnt[i] += sum == tgt;
  }
  int zsum = 0;
  sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum += v[i];
    if (sum == tgt && i > 1) zsum += cnt[i - 2];
  }
  cout << zsum << endl;
  return 0;
}
