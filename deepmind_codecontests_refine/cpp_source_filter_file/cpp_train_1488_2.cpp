#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e14 + 9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ult[n + 2];
    long long vet[n + 2];
    memset(ult, -1, sizeof ult);
    long long maiordif[n + 2];
    for (long long i = 0; i < (n); ++i) {
      cin >> vet[i];
    }
    for (long long i = 0; i < (n); ++i) {
      maiordif[i] = -1;
    }
    for (long long i = 0; i < (n); ++i) {
      maiordif[vet[i]] = max(i - ult[vet[i]], maiordif[vet[i]]);
      ult[vet[i]] = i;
    }
    for (long long i = 1; i < (n + 1); ++i) {
      maiordif[i] = max(n - ult[i], maiordif[i]);
    }
    long long cont[n + 2];
    for (long long i = 1; i < (n + 1); ++i) {
      cont[i] = INF;
    }
    for (long long i = 1; i < (n + 1); ++i) {
      cont[maiordif[i]] = min(i, cont[maiordif[i]]);
    }
    long long tem[n + 2];
    for (long long i = 0; i < (n + 1); ++i) tem[i] = INF;
    for (long long i = 1; i < (n + 1); ++i) {
      if (cont[i] != INF)
        tem[i] = min(tem[i - 1], cont[i]);
      else
        tem[i] = tem[i - 1];
    }
    long long ans[n + 2];
    for (long long i = 1; i < (n + 1); ++i) {
      ans[i] = INF;
    }
    for (long long i = 1; i < (n + 1); ++i) {
      ans[i] = tem[i];
    }
    for (long long i = 1; i < (n + 1); ++i) {
      if (ans[i] != INF)
        cout << ans[i] << " ";
      else
        cout << -1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
