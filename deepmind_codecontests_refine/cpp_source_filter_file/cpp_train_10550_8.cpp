#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  std::vector<long long> v(1e5 + 7);
  for (long long i = 0; i < 1e5 + 7; i++) {
    v[i] = i * (i + 1) / 2;
  }
  int flag = 0;
  for (long long i = 0; i < 1e5 + 7; i++) {
    if (binary_search(v.begin(), v.end(), n - v[i])) {
      flag = 1;
      break;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
