#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000 + 7;
const int N = 1e6 + 5;
int n;
vector<int> v;
int main() {
  cin >> n;
  for (int i = 1; i <= 9; i++) {
    long long d = i;
    while (d <= 1e10) {
      v.push_back(d);
      d *= 10;
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > n) {
      cout << v[i] - n << endl;
      exit(0);
    }
  }
}
