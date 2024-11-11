#include <bits/stdc++.h>
using namespace std;
int n, k;
int A[(100000 + 100)], B[(100000 + 100)], C[(100000 + 100)];
bool available[(100000 + 100)];
int cur_cnt;
vector<pair<long long, long long> > picked;
vector<int> order;
long long GCD(long long a, long long b) {
  if (!b) return a;
  return GCD(b, a % b);
}
void norm(long long &a, long long &b) {
  long long gcd = GCD(a, b);
  a /= gcd;
  b /= gcd;
}
bool getIntersect(
    int l1, int l2,
    pair<pair<long long, long long>, pair<long long, long long> > &point) {
  long long x_dn = A[l1] * 1LL * B[l2] - A[l2] * 1LL * B[l1];
  if (x_dn == 0) return false;
  long long x_n = B[l1] * 1LL * C[l2] - B[l2] * 1LL * C[l1];
  long long y_n = A[l1] * 1LL * C[l2] - A[l2] * 1LL * C[l1];
  long long y_dn = -x_dn;
  norm(x_n, x_dn);
  norm(y_n, y_dn);
  point = {{x_n, x_dn}, {y_n, y_dn}};
  return true;
}
bool passThrough(
    int idx,
    pair<pair<long long, long long>, pair<long long, long long> > point) {
  return A[idx] * 1LL * point.first.first * point.second.second +
             B[idx] * 1LL * point.second.first * point.first.second +
             C[idx] * 1LL * point.first.second * point.second.second ==
         0;
}
void getRandomOrder(vector<int> &order) {
  order.resize(n);
  for (int i = 0; i < n; i++) order[i] = i;
  shuffle(order.begin(), order.end(), default_random_engine(time(NULL)));
}
bool solve(int k) {
  if ((double)clock() / (CLOCKS_PER_SEC / 1000) > 1980) return false;
  if (cur_cnt != 0 && k == 0) return false;
  if (cur_cnt <= k) {
    for (int i = 0; i < n; i++) {
      if (available[i]) picked.push_back({i + 1, -1});
    }
    return true;
  }
  vector<int> cur_lines, pull_back;
  int counter = 0;
  for (int i : order)
    if (available[i]) {
      cur_lines.push_back(i);
      counter++;
      if (counter == k + 1) break;
    }
  for (int l1 = 0; l1 < ((int)(cur_lines).size()); l1++) {
    for (int l2 = l1 + 1; l2 < ((int)(cur_lines).size()); l2++) {
      if ((double)clock() / (CLOCKS_PER_SEC / 1000) > 1980) return false;
      pair<pair<long long, long long>, pair<long long, long long> > point;
      if (getIntersect(cur_lines[l1], cur_lines[l2], point)) {
        pull_back.clear();
        for (int i = 0; i < n; i++)
          if (passThrough(i, point) && available[i]) {
            available[i] = false;
            cur_cnt--;
            pull_back.push_back(i);
          }
        bool ret = solve(k - 1);
        if ((double)clock() / (CLOCKS_PER_SEC / 1000) > 1980) return false;
        if (ret == true) {
          picked.push_back({cur_lines[l1] + 1, cur_lines[l2] + 1});
          return true;
        }
        for (int line : pull_back) {
          available[line] = true;
          cur_cnt++;
        }
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(time(NULL));
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i] >> C[i];
    available[i] = 1;
  }
  getRandomOrder(order);
  cur_cnt = n;
  bool ok = solve(k);
  if (ok) {
    cout << "YES" << endl;
    cout << ((int)(picked).size()) << endl;
    for (pair<long long, long long> node : picked) {
      cout << node.first << ' ' << node.second << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
