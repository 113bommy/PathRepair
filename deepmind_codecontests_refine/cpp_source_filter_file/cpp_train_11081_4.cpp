#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v(4, 0);
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    v[i] += s.length() - 2;
  }
  char ch = 'C';
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != j) {
        if (v[i] > 2 * v[j]) {
          cnt++;
        }
        if (2 * v[i] < v[j]) {
          cnt--;
        }
      }
    }
    if (cnt == 3 || cnt == -3) {
      ch = (char)(65 + i);
      ans++;
    }
    cnt = 0;
  }
  if (ans != 1) {
    cout << "C\n";
  } else {
    cout << ch << "\n";
  }
  return 0;
}
