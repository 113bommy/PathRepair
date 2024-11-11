#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> cnt(n + 1, 0);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
    cnt[i] += sum;
  }
  int k;
  int num = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      if (i > 0) {
        k = j - i + 1 - (cnt[j] - cnt[i - 1]);
        num = max(k + cnt[i - 1] + cnt[n - 1] - cnt[j], num);
      } else if (i == 0) {
        k = j + 1 - cnt[j];
        num = max(k + cnt[n - 1] - cnt[j], num);
      }
    }
  cout << num;
}
