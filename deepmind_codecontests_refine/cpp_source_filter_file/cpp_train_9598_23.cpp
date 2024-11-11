#include <bits/stdc++.h>
using namespace std;
int buscaAcima(const vector<int> arr, int x) {
  int n = arr.size();
  int lo = 0, hi = n;
  while (lo < hi) {
    int middle = lo + (hi - lo) / 2;
    if (arr[middle] <= x) {
      lo = middle + 1;
    } else {
      hi = middle;
    }
  }
  return lo - 1;
}
int buscaAbaixo(const vector<int> arr, int x) {
  int hi = arr.size(), lo = 0;
  while (lo < hi) {
    int middle = lo + (hi - lo) / 2;
    if (arr[middle] >= x) {
      hi = middle;
    } else {
      lo = middle + 1;
    }
  }
  return lo - 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b;
  cin >> n >> a >> b;
  cout << n - max(a + 1, b - 1) + 1 << endl;
  return 0;
}
