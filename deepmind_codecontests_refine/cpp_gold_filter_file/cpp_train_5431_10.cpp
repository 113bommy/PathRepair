#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
double a[1 << 17];
int b[1 << 17], N;
ll pos_sum = 0, neg_sum = 0;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] > 0) {
      b[i] = ceil(a[i]);
      pos_sum += b[i];
    } else if (a[i] < 0) {
      b[i] = floor(a[i]);
      neg_sum += b[i];
    }
  }
  if (abs(pos_sum) < abs(neg_sum)) {
    for (int i = 0; i < N && abs(pos_sum) < abs(neg_sum); i++) {
      if (a[i] < 0 && ceil(a[i]) != b[i]) {
        b[i] = ceil(a[i]);
        neg_sum++;
      }
    }
  } else if (abs(pos_sum) > abs(neg_sum)) {
    for (int i = 0; i < N && abs(pos_sum) > abs(neg_sum); i++) {
      if (a[i] > 0 && floor(a[i]) != b[i]) {
        b[i] = floor(a[i]);
        pos_sum--;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << b[i] << "\n";
  }
}
