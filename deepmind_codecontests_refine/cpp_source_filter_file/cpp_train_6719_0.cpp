#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  a--;
  vector<int> vec;
  vec.resize(n);
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  for (int i = 0; i < n; i++) {
    if (a - i >= 0 && a + i < n) {
      if (vec[a - i] == 1 && vec[a + i] == 1) {
        count += vec[a - i];
        vec[a - i] = 0;
        count += vec[a + i];
        vec[a + i] = 0;
      }
    } else if (a - i >= 0) {
      count + vec[a - i];
    } else if (a + i < n) {
      count += vec[a + i];
    }
  }
  cout << count << endl;
}
