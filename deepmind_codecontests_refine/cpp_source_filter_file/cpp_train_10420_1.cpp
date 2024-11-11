#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x;
  cin >> n >> x;
  int ar[n], prev;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  prev = ar[0];
  for (int i = 1; i < n; i++) {
    if (prev == ar[i]) {
      cout << "0";
      exit(0);
    }
    prev = ar[i];
  }
  int process[n];
  for (int i = 0; i < n; i++) {
    process[i] = ar[i] & x;
    if (process[i] == ar[i]) {
      continue;
    }
    if (binary_search(ar, ar + n, prev)) {
      cout << "1";
      exit(0);
    }
  }
  sort(process, process + n);
  prev = process[0];
  for (int i = 1; i < n; i++) {
    if (prev == process[i]) {
      cout << "2";
      exit(0);
    }
    prev = process[i];
  }
  cout << "-1";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
