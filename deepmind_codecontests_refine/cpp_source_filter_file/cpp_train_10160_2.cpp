#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, l, x, y;
  cin >> n >> m >> k >> l;
  vector<pair<long long, long long>> arr;
  for (long long i = 0; i < k; i++) {
    cin >> x >> y;
    arr.push_back({x, y});
  }
  sort(arr.begin(), arr.end());
  for (long long i = 0; i < l; i++) {
    cin >> x >> y;
    pair<long long, long long> p = {x, y};
    long long counter = 0, flag = 0;
    for (long long j = 0; j < k; j++) {
      if (arr[j] == p) {
        cout << "Waste\n";
        flag = 1;
        break;
      } else if (arr[j] < p) {
        counter++;
      } else {
        break;
      }
    }
    if (flag != 1) {
      counter = ((x - 1) * m + y) - counter;
      counter = counter % 3;
      if (counter == 0) {
        cout << "Grapes\n";
      } else if (counter == 1) {
        cout << "Carrots\n";
      } else {
        cout << "kiwis\n";
      }
    }
  }
  return 0;
}
