#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-4;
const long long MOD = 1000000007ll;
template <typename T>
T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}
template <typename T>
vector<T> reads(int count) {
  vector<T> values;
  values.reserve(count);
  for (int i = 0; i < count; i++) values.push_back(read<T>());
  return values;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed;
  int min_A = 8;
  int min_B = 8;
  vector<string> v;
  for (int i = 0; i < (8); ++i) v.push_back(read<string>());
  for (int i = 0; i < (8); ++i) {
    for (int j = 0; j < (8); ++j) {
      if (v[j].at(i) != '.') {
        if (v[j].at(i) == 'W' && j < min_A) min_A = j;
        break;
      }
    }
  }
  for (int i = 0; i < (8); ++i) {
    for (int j = 7; j >= 0; j--) {
      if (v[j].at(i) != '.') {
        if (v[j].at(i) == 'B' && 7 - j < min_B) min_B = 7 - j;
        break;
      }
    }
  }
  cout << (min_A <= min_B ? 'W' : 'B');
}
