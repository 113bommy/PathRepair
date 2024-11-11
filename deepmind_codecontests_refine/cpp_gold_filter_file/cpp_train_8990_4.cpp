#include <bits/stdc++.h>
using namespace std;
class song {
 public:
  long double length;
  long double probability;
};
bool compare(song a, song b) {
  if ((a.length * a.probability / (100.0 - a.probability)) >
      (b.length * b.probability / (100.0 - b.probability)))
    return true;
  return false;
}
int main() {
  int i, j, n, m;
  long double l, p;
  cin >> n;
  song arr[n];
  long double total = 0.0;
  for (i = 0; i < n; i++) {
    cin >> l >> p;
    arr[i].length = l;
    arr[i].probability = p;
    total += ((100.0 - p) / 100.0);
  }
  sort(arr, arr + n, compare);
  long double result = 0.0;
  for (i = 0; i < n; i++) {
    total -= ((100.0 - arr[i].probability) / 100);
    result += (total * arr[i].length * (arr[i].probability / 100));
    result += arr[i].length;
  }
  cout << fixed << setprecision(9) << result << endl;
  return 0;
}
