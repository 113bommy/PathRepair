#include <bits/stdc++.h>
using namespace std;
int k, n1, n2, n3, t1, t2, t3, p1, p2, p3;
const int inf = 2e9;
queue<int> q1, q2, q3;
int main() {
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  p1 = k;
  int t = 0;
  for (int i = 0; i < n1; i++) {
    if (p1) {
      p1--;
      q1.push(t + t1);
    }
  }
  while (q1.size() || q2.size() || q3.size()) {
    t = inf;
    if (q1.size() && q1.front() < t) t = q1.front();
    if (q2.size() && q2.front() < t) t = q2.front();
    if (q3.size() && q3.front() < t) t = q3.front();
    while (q1.size() && t == q1.front()) {
      q1.pop();
      p2++;
      if (p1) {
        p1--;
        q1.push(t + t1);
      }
    }
    while (q1.size() < n1 && p1) {
      p1--;
      q1.push(t + t1);
    }
    while (q2.size() && t == q2.front()) {
      q2.pop();
      p3++;
      if (p2) {
        p2--;
        q2.push(t + t2);
      }
    }
    while (q2.size() < n2 && p2) {
      p2--;
      q2.push(t + t2);
    }
    while (q3.size() && t == q3.front()) {
      q3.pop();
      if (p3) {
        p3--;
        q3.push(t + t3);
      }
    }
    while (q3.size() < n3 && p3) {
      p3--;
      q3.push(t + t2);
    }
  }
  cout << t << endl;
}
