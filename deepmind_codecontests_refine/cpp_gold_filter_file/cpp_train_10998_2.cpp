#include <bits/stdc++.h>
using namespace std;
const int N = 131073;
long long v[N];
long long t[N];
long long sumT[N];
long long ansT[N];
long long ad[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    sumT[i] = sumT[i - 1] + t[i];
  }
  for (int i = 1; i <= n; ++i) {
    int finalFull = i - 1;
    long long leftOver = v[i];
    for (int bit = 20; bit >= 0; --bit) {
      int cur = finalFull + (1 << bit);
      if (cur > n) continue;
      if (sumT[cur] - sumT[i - 1] <= v[i]) {
        finalFull = cur;
        leftOver = v[i] - (sumT[cur] - sumT[i - 1]);
      }
    }
    ++ansT[i];
    --ansT[finalFull + 1];
    ad[finalFull + 1] += leftOver;
  }
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += ansT[i];
    cout << (long long)(t[i] * sum) + ad[i] << " ";
  }
  cout << "\n";
}
