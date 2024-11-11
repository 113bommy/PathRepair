#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> s;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    s.push_back(k);
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (s[j] > s[j + 1]) {
        swap(s[j], s[j + 1]);
        cout << j + 1 << "  " << j + 2 << endl;
      }
    }
  }
  return 0;
}
