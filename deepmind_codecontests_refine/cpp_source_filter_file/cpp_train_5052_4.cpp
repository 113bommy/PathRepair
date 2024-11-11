#include <bits/stdc++.h>
using namespace std;
struct req {
  int id;
  int time;
};
int main() {
  int n, b;
  cin >> n >> b;
  int t, d;
  long long current_minute = 0;
  queue<req> my_queue;
  int result[n];
  for (int i = 0; i < n; i++) {
    cin >> t >> d;
    while (!my_queue.empty() && t >= current_minute) {
      current_minute += my_queue.front().time;
      result[my_queue.front().id] = current_minute;
      my_queue.pop();
    }
    if (t >= current_minute) {
      current_minute = t + d;
      result[i] = current_minute;
    } else {
      if (my_queue.size() >= b)
        result[i] = -1;
      else
        my_queue.push({i, d});
    }
  }
  while (!my_queue.empty()) {
    current_minute += my_queue.front().time;
    result[my_queue.front().id] = current_minute;
    my_queue.pop();
  }
  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
  return 0;
}
