#include <bits/stdc++.h>
using namespace std;
struct node {
  long long int r, h, ind;
  double vol;
};
vector<double> volume(4 * 100000);
double query(long long int ss, long long int se, long long int qs,
             long long int qe, long long int si) {
  if (qs <= ss && qe >= se) return volume[si];
  if (qs > se || qe < ss || ss > se || qs > qe) return 0;
  long long int mid = ss + (se - ss) / 2;
  double q1 = query(ss, mid, qs, qe, 2 * si + 1);
  double q2 = query(mid + 1, se, qs, qe, 2 * si + 2);
  return max(q1, q2);
}
void update(long long int ss, long long int se, long long int ind,
            long long int si, long long int vol) {
  if (ss == se) {
    volume[si] = vol;
    return;
  }
  long long int mid = ss + (se - ss) / 2;
  if (ind >= ss && ind <= mid)
    update(ss, mid, ind, 2 * si + 1, vol);
  else
    update(mid + 1, se, ind, 2 * si + 2, vol);
  volume[si] = max(volume[2 * si + 1], volume[2 * si + 2]);
}
bool comp(node a, node b) {
  if (a.vol == b.vol) return a.ind > b.ind;
  return a.vol < b.vol;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  vector<node> cake(n);
  long long int x, y;
  for (long long int i = 0; i < n; i++) {
    cin >> x >> y;
    cake[i].r = x;
    cake[i].h = y;
    cake[i].ind = i;
    cake[i].vol = 1.0 * x * x * y;
  }
  sort(cake.begin(), cake.end(), comp);
  double ans = 0;
  for (int i = 0; i < n; i++) {
    double t = query(0, n - 1, 0, cake[i].ind - 1, 0);
    t += cake[i].vol;
    ans = max(ans, t);
    update(0, n - 1, cake[i].ind, 0, t);
  }
  cout << fixed << setprecision(9) << 3.14159265359 * ans << endl;
}
