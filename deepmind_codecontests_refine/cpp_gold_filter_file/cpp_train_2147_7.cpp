#include <bits/stdc++.h>
using namespace std;
int c[int(1e5 + 5)];
multiset<long long> timer1, timer2, timer3;
long long answer = 0;
int main() {
  int k1, k2, k3, t1, t2, t3, n;
  cin >> k1 >> k2 >> k3;
  cin >> t1 >> t2 >> t3;
  cin >> n;
  k1 = min(n, k1);
  k2 = min(n, k2);
  k3 = min(n, k3);
  for (int i = 0; i < k1; i++) timer1.insert(0);
  for (int i = 0; i < k3; i++) timer3.insert(0);
  for (int i = 0; i < k2; i++) timer2.insert(0);
  int pos1 = 0, pos2 = 0, pos3 = 0;
  for (int i = 0; i < n; i++) {
    long long res = 0;
    cin >> c[i];
    long long t = *timer1.begin();
    timer1.erase(timer1.begin());
    if (t > c[i]) {
      timer1.insert(t + t1);
      res += t - c[i];
      c[i] = t + t1;
    } else {
      timer1.insert(c[i] + t1);
      c[i] += t1;
    }
    t = *timer2.begin();
    timer2.erase(timer2.begin());
    if (t > c[i]) {
      timer2.insert(t + t2);
      res += t - c[i];
      c[i] = t + t2;
    } else {
      timer2.insert(c[i] + t2);
      c[i] += t2;
    }
    t = *timer3.begin();
    timer3.erase(timer3.begin());
    if (t > c[i]) {
      timer3.insert(t + t3);
      res += t - c[i];
      c[i] = t + t3;
    } else {
      timer3.insert(c[i] + t3);
      c[i] += t3;
    }
    if (res > answer) answer = res;
  }
  answer += t1 + t2 + t3;
  cout << answer;
  return 0;
}
