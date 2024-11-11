#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T>
typename T::value_type arr_sum(const T& v, int n) {
  typename T::value_type sum = 0;
  for (int i = (0); i < (n); ++i) sum += v[i];
  return sum;
}
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  n *= 2;
  vector<int> v(4);
  vector<int> res(2);
  for (int i = (0); i < (n); ++i) {
    ++v[((a[i] - '0') << 1) | (b[i] - '0')];
  }
  for (int i = (0); i < (n); ++i) {
    if (i % 2) {
      if (v[3] > 0) {
        ++res[1];
        --v[3];
      } else if (v[1] > 0) {
        ++res[1];
        --v[1];
      } else if (v[2] > 0) {
        --v[2];
      } else {
        --v[0];
      }
    } else {
      if (v[3] > 0) {
        ++res[0];
        --v[3];
      } else if (v[2] > 0) {
        ++res[0];
        --v[2];
      } else if (v[1] > 0) {
        --v[2];
      } else {
        --v[0];
      }
    }
  }
  if (res[0] > res[1]) {
    cout << "First";
  } else if (res[0] == res[1]) {
    cout << "Draw";
  } else {
    cout << "Second";
  }
}
