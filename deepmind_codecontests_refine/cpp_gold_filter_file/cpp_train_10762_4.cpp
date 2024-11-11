#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  queue<pair<int, int> > p, q;
  for (int i = 0; i < n; i++) {
    int t, c;
    cin >> t >> c;
    p.push({t, c});
  }
  int time = 0;
  int max_size = 0;
  int curr_max = 0;
  while (!p.empty()) {
    time++;
    if (time == p.front().first) {
      q.push(p.front());
      curr_max += p.front().second;
      p.pop();
    }
    if (!q.empty()) {
      if (time > q.front().first) {
        q.front().second--;
        curr_max--;
        if (q.front().second == 0) {
          q.pop();
        }
      }
    }
    max_size = max(max_size, curr_max);
  }
  while (!q.empty()) {
    time += q.front().second;
    q.pop();
  }
  cout << time << " " << max_size;
}
