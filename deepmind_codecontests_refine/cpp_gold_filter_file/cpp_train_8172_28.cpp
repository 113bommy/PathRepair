#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a;
  cin >> a;
  long long int sum[a];
  long long int diff[a];
  long long int x, y;
  for (long long int i = 0; i < a; i++) {
    cin >> x >> y;
    sum[i] = x + y;
    diff[i] = x - y;
  }
  sort(sum, sum + (a));
  sort(diff, diff + (a));
  long long int counter = 0, runnings = 1, runningd = 1;
  for (long long int i = 0; i < a; i++) {
    if (sum[i] == sum[i + 1]) {
      runnings += 1;
    } else {
      counter += runnings * (runnings - 1) / 2;
      runnings = 1;
    }
    if (diff[i] == diff[i + 1]) {
      runningd += 1;
    } else {
      counter += runningd * (runningd - 1) / 2;
      runningd = 1;
    }
  }
  cout << counter << endl;
}
