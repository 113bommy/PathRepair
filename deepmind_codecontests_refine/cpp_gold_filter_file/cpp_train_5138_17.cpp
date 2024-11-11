#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, count = 0;
  cin >> n;
  const int max_i = 2e5;
  int counter = 0;
  pair<pair<int, int>, int> data[max_i + 9];
  for (int i = 0; i < n; i++) {
    long long k, a0, x, y, m, t = 0, a = 0;
    cin >> k >> a0 >> x >> y >> m;
    for (int j = 0; j < k; j++) {
      if (counter <= max_i) {
        data[counter++] = make_pair(make_pair(t, a0), i);
      }
      a = (a0 * x + y) % m;
      if (a < a0 && j != k - 1) {
        t++;
      }
      a0 = a;
    }
    count = max(count, t);
  }
  cout << count << endl;
  if (counter <= max_i) {
    sort(data, data + counter);
    for (int i = 0; i < counter; i++) {
      cout << data[i].first.second << " " << data[i].second + 1 << endl;
    }
  }
}
