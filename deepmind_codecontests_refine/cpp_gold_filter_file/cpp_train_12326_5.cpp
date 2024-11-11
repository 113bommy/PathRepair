#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int* mem = new int[n + 1];
  long long int* sum = new long long int[n + 1];
  for (int i = 0; i < n; i++) scanf("%d", &mem[i + 1]);
  map<int, int> last;
  for (int i = 1; i <= n; i++) {
    last[mem[i]] = i;
  }
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1];
    if (mem[i] >= 0) sum[i] += mem[i];
  }
  long long int best = LONG_MIN;
  int pos;
  for (int i = 1; i <= n; i++) {
    int l = last[mem[i]];
    if (l == i) continue;
    long long int sm = sum[l] - sum[i - 1];
    if (mem[i] < 0) sm += 2 * mem[i];
    if (best < sm) {
      best = sm;
      pos = i;
    }
  }
  int cnt = pos - 1 + n - last[mem[pos]];
  ;
  int maxi = last[mem[pos]];
  for (int i = pos + 1; i < maxi; i++) {
    if (mem[i] < 0) cnt++;
  }
  cout << best << " " << cnt << endl;
  for (int i = 1; i < pos; i++) {
    cout << i << " ";
  }
  for (int i = pos + 1; i < maxi; i++) {
    if (mem[i] < 0) {
      cout << i << " ";
    }
  }
  for (int i = last[mem[pos]] + 1; i <= n; i++) {
    cout << i << " ";
  }
  cout << endl;
}
