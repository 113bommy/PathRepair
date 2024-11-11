#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int n1;
  cin >> n1;
  queue<int> q1;
  int x;
  for (int i = 0; i < n1; i++) {
    cin >> x;
    q1.push(x);
  }
  queue<int> q2;
  int n2;
  cin >> n2;
  for (int i = 0; i < n2; i++) {
    cin >> x;
    q2.push(x);
  }
  long long num = 1;
  for (int i = 1; i <= (n + 1); i++) {
    num *= i;
  }
  int f = 0;
  int i;
  for (i = 0; i < num; i++) {
    if (q1.empty()) {
      cout << i << " " << 1;
      return 0;
    } else if (q2.empty()) {
      cout << i << " " << 2;
      return 0;
    }
    int a = q1.front();
    int b = q2.front();
    q1.pop();
    q2.pop();
    if (a < b) {
      q2.push(a);
      q2.push(b);
    } else {
      q1.push(b);
      q1.push(a);
    }
  }
  if (q1.empty()) {
    cout << i << " " << 1;
  } else if (q2.empty()) {
    cout << i << " " << 2;
  } else {
    cout << -1;
  }
  return 0;
}
