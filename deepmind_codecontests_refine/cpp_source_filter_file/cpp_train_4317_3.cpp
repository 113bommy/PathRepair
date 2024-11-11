#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n], s[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    sum += ar[i];
    if (i == 0)
      s[i] = 1;
    else
      s[i] = s[i - 1] + ar[i - 1];
  }
  int st[sum + 1];
  int p = 1;
  for (int i = 0; i < n; i++) {
    for (int j = s[i] - 1; j < s[i] + ar[i] - 1; j++) {
      st[j] = p;
    }
    p++;
  }
  int k, d;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> d;
    cout << st[d] << endl;
  }
  return 0;
}
