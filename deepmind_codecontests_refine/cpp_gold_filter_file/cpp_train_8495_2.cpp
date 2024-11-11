#include <bits/stdc++.h>
using namespace std;
struct flight {
  int id;
  int cost;
  int time;
};
int main() {
  auto cmp_cost = [](flight one, flight two) { return one.cost < two.cost; };
  priority_queue<flight, vector<flight>, decltype(cmp_cost)> pqueue(cmp_cost);
  auto cmp_id = [](flight one, flight two) { return one.id > two.id; };
  priority_queue<flight, vector<flight>, decltype(cmp_id)> schedule(cmp_id);
  int n, k, i, temp;
  cin >> n >> k;
  i = 1;
  long long totalCost = 0;
  queue<int> input;
  for (int j = 0; j < n; ++j) {
    cin >> temp;
    input.push(temp);
  }
  long long queueCost = 0;
  for (; i <= k + n; ++i) {
    if (i <= n) {
      temp = input.front();
      input.pop();
      queueCost += temp;
      flight newflight;
      newflight.id = i;
      newflight.cost = temp;
      pqueue.push(newflight);
    }
    if (i > k) {
      flight departured = pqueue.top();
      pqueue.pop();
      queueCost -= departured.cost;
      departured.time = i;
      schedule.push(departured);
    }
    totalCost += queueCost;
  }
  cout << totalCost << endl;
  for (int i = 0; i < n; ++i) {
    cout << schedule.top().time << " ";
    schedule.pop();
  }
  return 0;
}
