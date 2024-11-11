#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> Ones;
  int n_ones = 0;
  long long n_ways = 1;
  bool flag = true;
  int index = -1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) {
      n_ones++;
      if (flag) {
        index = i;
        flag = false;
      }
    }
  }
  index++;
  if (n_ones < 2) {
    cout << (n_ones && 1);
    return 0;
  }
  n_ones--;
  int zero_count = 1;
  while (arr[index] == 0 && index < n && n_ones > 1) {
    zero_count++;
    index++;
  }
  Ones.push_back(zero_count);
  index++;
  for (; index < n && n_ones > 1; index++) {
    n_ones--;
    zero_count = 1;
    while (arr[index] == 0 && index < n) {
      zero_count++;
      index++;
    }
    Ones.push_back(zero_count);
  }
  for (int i = 0; i < Ones.size(); i++) {
    n_ways *= Ones[i];
  }
  cout << n_ways << "\n";
  return 0;
}
