#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, tmp, s = 0;
  cin >> n;
  deque<int> a, b;
  long long n1, n2;
  cin >> n1;
  for (int i = 0; i < n1; i++) cin >> tmp, a.push_back(tmp);
  cin >> n2;
  for (int i = 0; i < n2; i++) cin >> tmp, b.push_back(tmp);
  int x, y;
  while (s < n * n) {
    x = a.front(), y = b.front();
    s++;
    if (x < y) {
      b.pop_front();
      b.push_back(x), b.push_back(y);
      a.pop_front();
      if (a.empty()) {
        cout << s << " " << 2 << "\n";
        return 0;
      }
    } else {
      a.pop_front();
      a.push_back(y), a.push_back(x);
      b.pop_front();
      if (b.empty()) {
        cout << s << " " << 1 << "\n";
        return 0;
      }
    }
  }
  {
    cout << -1 << "\n";
    return 0;
  }
}
