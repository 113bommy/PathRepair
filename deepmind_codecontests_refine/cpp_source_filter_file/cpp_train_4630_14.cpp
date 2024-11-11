#include <bits/stdc++.h>
using namespace std;
int main() {
  queue<int> q1, q2, q3;
  int n, t;
  cin >> n;
  int i = 1;
  while (n--) {
    cin >> t;
    if (t == 1) {
      q1.push(i);
    } else if (t == 2) {
      q2.push(i);
    } else {
      q3.push(i);
    }
    i++;
  }
  int min = q1.size();
  if (q2.size() < min) {
    min = q1.size();
  }
  if (q3.size() < min) {
    min = q3.size();
  }
  if (min == 0) {
    cout << 0 << endl;
  } else {
    cout << min << endl;
    while (min--) {
      cout << q1.front() << " " << q2.front() << " " << q3.front() << endl;
      q1.pop();
      q2.pop();
      q3.pop();
    }
  }
  return 0;
}
