#include <bits/stdc++.h>
using namespace std;
ifstream fin("123.in");
ofstream fout("123.out");
int n, a[10005], k;
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    a[i] += x;
    k += a[i];
    int t = log2(n - i);
    a[i + (1 << t)] += a[i];
    cout << k << "\n";
  }
  return 0;
}
