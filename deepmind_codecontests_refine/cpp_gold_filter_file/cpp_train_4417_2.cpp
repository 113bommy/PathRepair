#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<long long, int> station[300000 + 100];
int main() {
  cin >> n;
  for (int i = 0; i < (n); i++) {
    cin >> station[i].first;
    station[i].first += 100001000;
    station[i].second = i + 1;
  }
  sort(station, station + n);
  cin >> k;
  double now_length = 0;
  double mysub = 0;
  int min_index = k - 1;
  for (int i = 0; i < (k); i++) {
    now_length += i * station[i].first - (k - 1 - i) * station[i].first;
    mysub += 2 * station[i].first;
  }
  double min_length = now_length;
  for (int i = k; i < (n); i++) {
    now_length += (k - 1) * station[i].first;
    now_length += (k - 1) * station[i - k].first;
    mysub -= 2 * station[i - k].first;
    now_length -= mysub;
    mysub += 2 * station[i].first;
    if (now_length < min_length) {
      min_length = now_length;
      min_index = i;
    }
  }
  for (int i = 0; i < (k); i++) {
    cout << station[min_index - i].second << (i == k - 1 ? "\n" : " ");
  }
  return 0;
}
