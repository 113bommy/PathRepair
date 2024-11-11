#include <bits/stdc++.h>
using namespace std;
vector<int> s;
int main() {
  int n;
  cin >> n;
  for (int i = 1;; i++) {
    int t = (pow(2, i) - 1) * pow(2, i - 1);
    if (t > 100000) break;
    s.push_back(t);
  }
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    int t = s[i];
    if (n % t == 0) {
      cnt = max(cnt, t);
    }
  }
  cout << cnt << endl;
}
