#include <bits/stdc++.h>
using namespace std;
const int MAX = 100010;
int n;
long long m;
struct xiao {
  int num;
  long long x;
  friend bool operator<(xiao a, xiao b) { return a.x > b.x; }
};
priority_queue<xiao> que;
struct s {
  long long coin;
  long long note;
};
xiao saaa;
long long ans;
s money[MAX];
long long day[MAX];
long long w[MAX];
bool duasi[MAX];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &day[i]);
    money[i].note = day[i] / 100;
    day[i] = day[i] % 100;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    duasi[i] = false;
  }
  for (int i = 1; i <= n; i++) {
    if (m >= day[i]) {
      if (day[i] == 0) {
        duasi[i] = true;
        continue;
      }
      m -= day[i];
      money[i].coin = day[i];
      saaa.num = i;
      saaa.x = w[i] * (100 - day[i]);
      que.push(saaa);
    } else {
      xiao need;
      xiao now;
      need.x = w[i] * (100 - day[i]);
      need.num = i;
      if (que.empty()) {
        ans += need.x;
        m += 100 - day[i];
        duasi[i] = true;
        money[i].note++;
        money[i].coin = day[i];
      } else {
        now = que.top();
        if (need.x <= now.x) {
          ans += need.x;
          m += 100 - day[i];
          duasi[i] = true;
          money[i].note++;
          money[i].coin = day[i];
        } else {
          ans += now.x;
          que.pop();
          m += 100 - day[now.num];
          money[now.num].note++;
          que.push(need);
          duasi[now.num] = true;
          money[i].coin = day[i];
        }
      }
    }
  }
  printf("%I64d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (duasi[i] == false)
      printf("%I64d %I64d\n", money[i].note, money[i].coin);
    else
      printf("%I64d 0\n", money[i].note);
  }
  return 0;
}
