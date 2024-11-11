#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main(int argc, char** argv) {
  stringstream out;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> b(200001);
  long long ind = 0;
  for (long long i = 0, max_i = 200001; i < max_i; ++i) b[i] = 0;
  for (long long i = 0, max_i = n; i < max_i; ++i) {
    cin >> a[i];
    ++b[a[i]];
  }
  for (long long i = 0, max_i = n; i < max_i; ++i) {
    if (b[i] > b[ind]) ind = i;
  }
  long long pos = 0;
  for (long long i = 0, max_i = n; i < max_i; ++i)
    if (a[i] == ind) {
      pos = i;
      break;
    }
  long long c = 0;
  for (long long i = pos - 1; i >= 0; --i) {
    if (a[i] != ind) {
      ++c;
      if (a[i] > ind)
        out << "2 " << i + 1 << " " << i + 2 << "\n";
      else
        out << "1 " << i + 1 << " " << i + 2 << "\n";
    }
  }
  for (long long i = pos + 1, max_i = n; i < max_i; ++i) {
    if (a[i] != ind) {
      ++c;
      if (a[i] > ind)
        out << "2 " << i + 1 << " " << i << "\n";
      else
        out << "1 " << i + 1 << " " << i << "\n";
    }
  }
  cout << c << "\n" << out.str();
  return 0;
}
