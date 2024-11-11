#include <bits/stdc++.h>
using namespace std;
pair<int, int> probs[200005];
unordered_map<int, int> times;
bool check(int k, int n, int T) {
  long long int ans = 0;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    if (probs[i].first < k) break;
    pq.push(-1 * times[probs[i].second]);
  }
  if (pq.size() < k) return false;
  int alias = k;
  while (alias > 0) {
    ans += -1 * pq.top();
    pq.pop();
    alias--;
  }
  if (ans > T) return false;
  return true;
}
void printAnswer(int k, int n) {
  long long int ans = 0;
  priority_queue<pair<int, int> > pq;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (probs[i].first < k) break;
    pq.push({-1 * times[probs[i].second], probs[i].second});
  }
  assert(pq.size() >= k);
  int alias = k;
  while (alias > 0) {
    ans += -1 * pq.top().first;
    v.push_back(pq.top().second);
    pq.pop();
    alias--;
  }
  cout << k << endl;
  cout << k << endl;
  for (int p : v) {
    printf("%d ", p + 1);
  }
  cout << endl;
}
int main() {
  int n, T;
  cin >> n >> T;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    probs[i] = {a, i};
    times[i] = b;
  }
  sort(probs, probs + n, greater<pair<int, int> >());
  int low = 0, high = n + 1;
  int mid;
  for (int i = 0; i < 20; i++) {
    mid = low + high;
    mid = mid / 2;
    if (check(mid, n, T)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  printAnswer(mid, n);
  return 0;
}
