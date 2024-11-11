#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  vector<int> p;
  deque<int> path;
  cin >> n;
  p.push_back(0);
  p.push_back(1);
  for (int i = 2; i <= n; i++) {
    cin >> temp;
    p.push_back(temp);
  }
  for (int i = n; i != 1; i = p[i]) {
    path.push_front(i);
  }
  path.push_front(1);
  for (auto n : path) {
    cout << n << " ";
  }
  return 0;
}
