#include <bits/stdc++.h>
using namespace std;
int main() {
  long long H, n, min1 = 10e9, all_delt = 0;
  long long counter = 0;
  cin >> H >> n;
  vector<long long> input(n);
  for (int i = 0; i < n; i++) {
    cin >> input[i];
    all_delt += input[i];
    if (all_delt < min1) min1 = all_delt;
  }
  if (H + min1 > 0 && all_delt >= 0) {
    cout << -1;
    return 0;
  } else if (H + min1 <= 0) {
    long long copy = H, i = 0;
    while (copy > 0) {
      copy += input[i];
      i++;
    }
    cout << i;
    return 0;
  } else {
    long long copy = H;
    copy += min1;
    counter += ceil(double(abs(copy)) / double(abs(all_delt)));
    copy -= min1;
    copy += counter * all_delt;
    counter *= n;
    long long index = 0;
    while (copy > 0) {
      copy += input[index];
      index++;
      counter++;
    }
    cout << counter;
  }
}
