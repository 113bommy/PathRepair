#include <bits/stdc++.h>
using namespace std;
int N, W;
int A[300010], B[300010];
pair<int, int> pairs[300010];
long long res;
short ans[300010];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    pq1, pq2;
priority_queue<pair<int, int> > back;
int main() {
  ios_base::sync_with_stdio(false);
  if (fopen("codeforces436E.in", "r")) freopen("codeforces436E.in", "r", stdin);
  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    pq1.push(pair<int, int>(A[i], i));
    pq2.push(pair<int, int>(B[i], i));
  }
  for (int i = 0; i < W; i++) {
  get_rid_of_garbage_data:
    while (!pq1.empty()) {
      int p = pq1.top().first, d = pq1.top().second;
      if (ans[d] == 2) {
        pq1.pop();
        continue;
      } else if (ans[d] == 1) {
        if (p != B[d] - A[d]) {
          pq1.pop();
          continue;
        }
      } else {
        if (p != A[d]) {
          pq1.pop();
          continue;
        }
      }
      break;
    }
    while (!pq2.empty()) {
      int p = pq2.top().first, d = pq2.top().second;
      if (ans[d] == 0) {
        if (p != B[d]) {
          pq2.pop();
          continue;
        }
      } else {
        pq2.pop();
        continue;
      }
      break;
    }
    while (!back.empty()) {
      int p = back.top().first, d = back.top().second;
      if (ans[d] == 2) {
        if (p != B[d] - A[d]) {
          back.pop();
          continue;
        }
      } else if (ans[d] == 1) {
        if (p != A[d]) {
          back.pop();
          continue;
        }
      } else {
        back.pop();
        continue;
      }
      break;
    }
  calculate:
    bool p1 = true;
    int cost = pq1.top().first;
    if (!back.empty() && !pq2.empty()) {
      int diff = pq2.top().first - back.top().first;
      if (cost > diff) {
        cost = diff;
        p1 = false;
      }
    }
    res += cost;
    if (p1) {
      back.push(pq1.top());
      int ind = pq1.top().second;
      pq1.pop();
      ans[ind]++;
      if (ans[ind] == 1) pq1.push(pair<int, int>(B[ind] - A[ind], ind));
    } else {
      pq1.push(back.top());
      int ind = pq1.top().second;
      back.pop();
      ans[ind]--;
      if (ans[ind] == 0) pq2.push(pair<int, int>(B[ind], ind));
      ind = pq2.top().second;
      ans[ind] = 2;
      back.push(pair<int, int>(B[ind] - A[ind], ind));
    }
  }
  cout << res << endl;
  for (int i = 0; i < N; i++) cout << ans[i];
  cout << endl;
  return 0;
}
