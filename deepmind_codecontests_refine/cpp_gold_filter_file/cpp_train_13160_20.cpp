#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> num[400000];
long long ans[400000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long t;
    cin >> t;
    num[i] = pair<long long, long long>(t, i);
  }
  sort(num, num + n);
  long long yu = 0;
  for (int i = 1; i < n; i++) {
    if (num[i].first <= num[i - 1].first)
      num[i].first += -num[i].first + num[i - 1].first + 1;
  }
  for (int i = 0; i < n; i++) ans[num[i].second] = num[i].first;
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
