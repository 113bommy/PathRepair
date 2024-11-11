#include <bits/stdc++.h>
using namespace std;
struct Computer {
  long long cur;
  int usage;
  long long days;
  bool operator<(const Computer &oth) const { return days > oth.days; }
};
int N, K;
long long init[200005];
int usage[200005];
long long days[200005];
bool try_charge(long long charge) {
  priority_queue<Computer> pq;
  for (int i = 1; i <= N; i++) pq.push({init[i], usage[i], days[i]});
  for (int day = 0; day < K; day++) {
    Computer x = pq.top();
    pq.pop();
    if (x.days < day) return false;
    pq.push({x.cur + charge, x.usage, (x.cur + charge) / x.usage});
  }
  return true;
}
int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> init[i];
  for (int i = 1; i <= N; i++) {
    cin >> usage[i];
    days[i] = init[i] / usage[i];
  }
  long long lo = -1;
  long long hi = 5e12;
  while (hi - lo != 1) {
    long long mid = (lo + hi) / 2;
    if (try_charge(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << (hi == 5e12 ? -1 : hi);
}
