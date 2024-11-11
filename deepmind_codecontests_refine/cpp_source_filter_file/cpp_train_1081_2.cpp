#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100001;
int N;
long long A[MAX_N], B[MAX_N], C[MAX_N];
vector<pair<long long, long long> > intervals;
vector<int> lines;
int find_intersection_x(int d1, int d2) {
  long long a1 = B[d1];
  long long b1 = C[d1];
  long long a2 = B[d2];
  long long b2 = C[d2];
  return (b2 - b1) / (a1 - a2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= N; i++) cin >> B[i];
  intervals.push_back(pair<long long, long long>(LLONG_MIN, LLONG_MAX));
  lines.push_back(1);
  stack<int> s;
  s.push(1);
  C[1] = 0;
  for (int i = 2, id = 0; i <= N; i++) {
    int di = s.top();
    while (id < intervals.size() && intervals[id].second <= A[i]) {
      id++;
    }
    int lineid = lines[id];
    long long a = B[lineid];
    long long b = C[lineid];
    C[i] = b + a * A[i];
    long long xp = find_intersection_x(di, i);
    while (!intervals.empty() && xp <= intervals.back().first) {
      s.pop();
      lines.pop_back();
      intervals.pop_back();
      di = s.top();
      xp = find_intersection_x(di, i);
    }
    s.push(i);
    lines.push_back(i);
    intervals.back().second = xp;
    intervals.push_back(pair<long long, long long>(xp, LLONG_MAX));
  }
  cout << C[N];
  return 0;
}
