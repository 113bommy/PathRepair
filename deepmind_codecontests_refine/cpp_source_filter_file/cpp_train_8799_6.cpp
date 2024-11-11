#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, num;
  std::deque<int>::iterator it;
  cin >> k >> m >> n;
  std::deque<int> d;
  for (int i = 0; i < n; i++) {
    cin >> num;
    d.push_back(num);
  }
  int time = 0, pos;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      pos = 0;
      cin >> num;
      for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
        pos++;
        if (*it == num) break;
      }
      time = time + pos;
      d.erase(d.begin() + pos);
      d.push_front(num);
    }
  }
  cout << time;
}
