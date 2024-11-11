#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i, j, k;
  int ar[n + 1];
  long long int ans = 0;
  int freq[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  memset(freq, 0, sizeof(freq));
  int num_odd = 0;
  for (i = 1; i <= n; i++) {
    freq[ar[i]]++;
  }
  for (i = 1; i <= n; i++) {
    if (freq[i] % 2 == 1) num_odd++;
  }
  if (num_odd > 1) {
    cout << "0\n";
    return 0;
  }
  for (i = 1; i <= (n + 1) / 2; i++) {
    if (ar[i] != ar[n + 1 - i]) break;
  }
  if (i > (n + 1) / 2) {
    ans = n;
    cout << ans * (ans + 1) / 2 << endl;
    return 0;
  }
  memset(freq, 0, sizeof(freq));
  for (j = i; j <= n + 1 - i; j++) {
    freq[ar[j]]++;
  }
  long long int extboth = (long long int)i - 1;
  ans = (long long int)extboth;
  ans = ans * ans;
  int odd = -1;
  for (j = 1; j <= n; j++) {
    if (freq[j] % 2 == 1) odd = j;
  }
  int leftfreq[n + 1], rightfreq[n + 1];
  memset(leftfreq, 0, sizeof(leftfreq));
  memset(rightfreq, 0, sizeof(rightfreq));
  for (j = 1; j <= n; j++) {
    leftfreq[j] = freq[j];
  }
  for (j = n + 1 - i;; j--) {
    rightfreq[ar[j]]++;
    leftfreq[ar[j]]--;
    if (j == (n + 2) / 2 and ar[j] == odd) continue;
    if (j < (n + 2) / 2 and ar[j] == ar[n + 1 - j]) continue;
    if (rightfreq[ar[j]] > leftfreq[ar[j]]) break;
  }
  ans += ((long long int)(n - j + 2 - i)) * (extboth + 1);
  memset(rightfreq, 0, sizeof(rightfreq));
  memset(leftfreq, 0, sizeof(leftfreq));
  for (j = 1; j <= n; j++) {
    rightfreq[j] = freq[j];
  }
  for (j = i;; j++) {
    rightfreq[ar[j]]--;
    leftfreq[ar[j]]++;
    if (j == (n + 1) / 2 and ar[j] == odd) continue;
    if (j > (n + 1) / 2 and ar[j] == ar[n + 1 - j]) continue;
    if (rightfreq[ar[j]] < leftfreq[ar[j]]) break;
  }
  ans += ((long long int)(j - i + 1)) * (extboth + 1);
  ans--;
  cout << ans << endl;
  return 0;
}
