#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 * 1000;
pair<int, int> sarr[MAXN + 10];
int arr[MAXN + 10];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sarr[i].first = arr[i];
    sarr[i].second = i;
  }
  sort(sarr, sarr + n);
  arr[sarr[0].second] = sarr[0].first;
  for (int i = 1; i < n; i++) {
    if (sarr[i].first <= sarr[i - 1].first) {
      sarr[i].first += sarr[i].first - sarr[i - 1].first + 1;
    }
    arr[sarr[i].second] = sarr[i].first;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
