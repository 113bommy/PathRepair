#include <bits/stdc++.h>
using namespace std;
void fastInOut();
long long arr[100000];
int n, m;
int bs(int h) {
  int st = 0, ed = n - 1;
  int med = (st + ed) / 2;
  while (st < ed) {
    if (h <= arr[med]) {
      ed = med;
    } else if (h > arr[med]) {
      st = med + 1;
    }
    med = (st + ed) / 2;
  }
  return med + 1;
}
int main() {
  fastInOut();
  cin >> n >> m;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr[i] = x * y + prev;
    if (i == 0)
      prev = x * y;
    else
      prev = arr[i];
  }
  for (int i = 0; i < m; i++) {
    int h;
    cin >> h;
    cout << bs(h) << endl;
  }
  return 0;
}
void fastInOut() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
