#include <bits/stdc++.h>
using namespace std;
struct __timestamper {};
int main(void) {
  int n;
  cin >> n;
  vector<int> b, c;
  unordered_map<int, int> tek;
  for (int i = 3; i <= n; i += 2) {
    b.push_back(i);
    tek[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (((int)(b).size()) == 0) {
      b.push_back(1);
      tek[1] = 1;
    }
    if (!tek[i] && abs(b.back() - i) != 1) {
      tek[i] = 1;
      b.push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!tek[i] && abs(b.back() - i) != 1) {
      tek[i] = 1;
      b.push_back(i);
    }
  }
  for (int i = 0; i < ((int)(b).size()) - 1; i++) {
    assert(abs(b[i] - b[i + 1]) != 1);
  }
  cout << ((int)(b).size()) << endl;
  for_each((b).begin(), (b).end(), [&](int x) { cout << x << ' '; });
  return 0;
}
