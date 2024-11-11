#include <bits/stdc++.h>
using namespace std;
bool set_bit(long long x, int y) {
  while (y--) {
    x >>= 1;
  }
  if (x & 1)
    return 1;
  else
    return 0;
}
long long pow_(long long x) {
  long long m = 1;
  for (int i = 0; i < x; i++) {
    m *= 2;
  }
  return m;
}
int main() {
  long long x, y;
  long long arr[100000];
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> arr[i];
  }
  vector<long long> res;
  for (int i = 0; i <= 30; i++) {
    vector<long long> vec;
    long long andd;
    for (int j = 0; j < x; j++) {
      if (set_bit(arr[j], i)) {
        vec.push_back(arr[j]);
      }
    }
    for (int j = 0; j < vec.size(); j++) {
      if (j == 0) {
        andd = vec[j];
      } else
        andd = andd & vec[j];
    }
    if (vec.size() > 0 && andd % pow_(i) == 0) res = vec;
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    if (i != res.size() - 1) {
      cout << res[i] << " ";
    } else {
      cout << res[i] << endl;
    }
  }
  return 0;
}
