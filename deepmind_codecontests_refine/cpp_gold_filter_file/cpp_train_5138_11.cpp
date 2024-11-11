#include <bits/stdc++.h>
using namespace std;
struct st {
  int prio;
  int num;
  int data;
  st(int p = 0, int n = 0, int d = 0) : prio(p), num(n), data(d) {}
};
vector<st> ve;
int ai[5005];
int xi[5005];
int yi[5005];
int mi[5005];
int ki[5005];
int n;
bool cmp(const st& a, const st& b) {
  if (a.prio > b.prio)
    return false;
  else if (a.prio < b.prio)
    return true;
  else {
    if (a.data >= b.data)
      return false;
    else
      return true;
  }
}
int main() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> ki[i] >> ai[i] >> xi[i] >> yi[i] >> mi[i];
    sum += ki[i];
  }
  int ans = 0;
  bool disp = sum <= 200000 ? true : false;
  bool flag = true;
  while (flag) {
    ans++;
    flag = false;
    for (int i = 1; i <= n; ++i) {
      while (ki[i] > 0) {
        ki[i]--;
        flag = true;
        if (disp) {
          ve.push_back(st(ans, i, ai[i]));
        }
        int temp = ai[i];
        ai[i] = ((long long)ai[i] * xi[i] + yi[i]) % mi[i];
        if (ai[i] < temp) break;
      }
    }
  }
  cout << ans - 2 << endl;
  if (disp) {
    sort(ve.begin(), ve.end(), cmp);
    for (int i = 0; i < sum; ++i) {
      cout << ve[i].data << " " << ve[i].num << endl;
    }
  }
  return 0;
}
