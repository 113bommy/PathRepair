#include <bits/stdc++.h>
using namespace std;
const long long LINF = ~(((long long)0x1) << 63) / 2;
const int INF = 0X3F3F3F3F;
const double eps = 1e-7;
int a[50000];
int ok[50000];
int n;
vector<int> first, second;
bool solve(int pree, int pre) {
  int i, j, k, last;
  memset(ok, 0, sizeof(ok));
  ok[pree] = ok[pre] = 1;
  int m = 2;
  first.clear();
  first.push_back(pree);
  first.push_back(pre);
  second.clear();
  for (i = pre + 1; i < n; i++)
    if (a[i] - a[pre] == a[pre] - a[pree]) {
      ok[i] = 1;
      pree = pre;
      pre = i;
      first.push_back(i);
      m++;
    }
  if (m == n) {
    ok[pre] = 0;
    return true;
  }
  pre = -1;
  pree = -1;
  int preee = -1;
  for (i = 0; i < n; i++)
    if (!ok[i] && preee == -1)
      preee = i;
    else if (!ok[i] && pree == -1) {
      pree = i;
    } else if (!ok[i] && pre == -1) {
      pre = i;
      break;
    }
  if (pre == -1 || pree == -1) return true;
  vector<int> now;
  int c = -1;
  bool flag = false;
  if (abs(a[pre] - a[pree]) != abs(a[pree] - a[preee]) &&
      ((a[pre] - a[pree]) % (a[pree] - a[preee]) != 0 &&
       (a[pree] - a[preee]) % (a[pre] - a[pree]) != 0))
    return false;
  if (abs(a[pre] - a[pree]) > abs(a[pree] - a[preee])) {
    c = a[pree] - a[preee];
    for (i = pree + 1; i < pre; i++)
      if (a[pree] + c == a[i]) {
        now.push_back(i);
        pree = i;
      }
    if (a[pree] + c != a[pre]) return false;
  } else if (abs(a[pre] - a[pree]) < abs(a[pree] - a[preee])) {
    c = a[pre] - a[pree];
    for (i = preee + 1; i < pree; i++)
      if (a[preee] + c == a[i]) {
        now.push_back(i);
        preee = i;
      }
    if (a[preee] + c != a[pree]) return false;
  }
  second.push_back(pre);
  second.push_back(pree);
  for (i = pre + 1; i < n; i++)
    if (!ok[i] && a[i] - a[pre] != a[pre] - a[pree]) {
      break;
    } else if (!ok[i]) {
      pree = pre;
      pre = i;
      second.push_back(i);
    } else if (ok[i] && a[i] - a[pre] == a[pre] - a[pree]) {
      pree = pre;
      pre = i;
      now.push_back(i);
      second.push_back(i);
    }
  if (i != n) return false;
  m = now.size();
  int cur = second.size() - 1;
  for (i = m - 1; i >= 0; i--) {
    if (second[cur] != now[i])
      break;
    else
      cur--;
  }
  cur = first.size() - 1;
  for (; i >= 0; i--) {
    if (first[cur] != now[i])
      return false;
    else {
      ok[now[i]] = 0;
      cur--;
    }
  }
  return true;
}
void print() {
  int i;
  for (i = 0; i < n; i++)
    if (ok[i]) {
      cout << a[i];
      break;
    }
  for (i = i + 1; i < n; i++)
    if (ok[i]) cout << " " << a[i];
  cout << endl;
  for (i = 0; i < n; i++)
    if (!ok[i]) {
      cout << a[i];
      break;
    }
  for (i = i + 1; i < n; i++)
    if (!ok[i]) cout << " " << a[i];
  cout << endl;
}
int main() {
  int i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  if (solve(0, 1)) {
    print();
  } else if (solve(0, 2)) {
    print();
  } else if (solve(1, 2)) {
    print();
  } else
    printf("No solution\n");
  return 0;
}
