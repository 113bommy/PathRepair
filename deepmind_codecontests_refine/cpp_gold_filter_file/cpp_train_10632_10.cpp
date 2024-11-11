#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long dam[n];
  for (int i = 0; i < n; i++) {
    cin >> dam[i];
  }
  string str;
  cin >> str;
  long long st, cnt, sm, sum = 0;
  for (int i = 0; i < n;) {
    st = i, cnt = 1, sm = 0;
    sm += dam[i];
    i++;
    while (i < n && str[i] == str[i - 1]) {
      sm += dam[i];
      cnt++;
      i++;
    }
    if (cnt > k) {
      sort(dam + st, dam + i);
      for (int j = i - 1; j >= i - k; j--) {
        sum += dam[j];
      }
    } else {
      sum += sm;
    }
  }
  cout << sum;
}
