#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i{0}, x; i < n; ++i) {
    cin >> x;
    v[i] = x;
  }
  sort(begin(v), end(v));
  int count{0};
  for (int i{1}, gap; i < n; ++i) {
    gap = v[i] - v[i - 1] - 1;
    if (gap) {
      count += gap;
    }
  }
  cout << count << endl;
}
