#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, p;
  cin >> n >> h >> p;
  unsigned long long time = 0;
  int queued = 0;
  queue<int> potatoes;
  while (n--) {
    int tmp;
    cin >> tmp;
    potatoes.push(tmp);
  }
  while (queued > 0 || !potatoes.empty()) {
    int next = potatoes.front();
    while ((h - queued) >= next && !potatoes.empty()) {
      queued += next;
      potatoes.pop();
      next = potatoes.front();
    }
    if (queued > p) {
      time += queued / p;
      queued %= p;
    } else {
      time++;
      queued = 0;
    }
  }
  cout << time << endl;
}
