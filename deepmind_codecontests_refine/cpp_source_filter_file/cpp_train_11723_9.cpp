#include <bits/stdc++.h>
using namespace std;
int const nmax = 100000;
int const domain = 1000000;
struct Person {
  int x;
  int v;
  bool operator<(Person other) const { return (x < other.x); }
};
int n, nl, nr;
int s;
Person pl[1 + nmax], pr[1 + nmax];
bitset<1 + domain> okl, okr;
double timetodest(int distp, int vp, int distray) {
  double timep = 1.0L * distp / vp;
  double timehit = 1.0L * (distray - distp) / (s - vp);
  if (timep <= timehit)
    return timep;
  else {
    double disthit = distp - timehit * vp;
    return timehit + (disthit / (vp + s));
  }
}
void checktime(double target, Person *p, int np, bitset<1 + domain> *ok) {
  for (int i = 1; i <= np; i++) {
    if (p[i].x <= p[i].v * target) {
      for (int j = 1; j < domain; j++) (*ok)[j] = 1;
      return;
    }
  }
  int i = 1;
  for (int j = 0; j <= domain; j++) {
    bool flag = false;
    while (flag == false && i <= np && p[i].x <= j) {
      if (timetodest(p[i].x, p[i].v, j) <= target)
        flag = true;
      else
        i++;
    }
    (*ok)[j] = flag;
  }
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int x, v, dir;
    cin >> x >> v >> dir;
    if (dir == 1) {
      nl++;
      pl[nl] = {x, v};
    } else {
      nr++;
      pr[nr] = {domain - x, v};
    }
  }
  sort(pl + 1, pl + nl);
  sort(pr + 1, pr + nr);
  double t1 = 0, t2 = domain, tmid;
  double deltat = 1;
  double stop = 0.0000000001L;
  while (stop < deltat) {
    tmid = (t1 + t2) / 2;
    deltat = (tmid - t1) / 2;
    checktime(tmid, pl, nl, &okl);
    checktime(tmid, pr, nr, &okr);
    int flag = 0, i = 0;
    while (flag == 0 && i <= domain) {
      if (okl[i] == 1 && okr[domain - i] == 1) flag = 1;
      i++;
    }
    if (flag == 1)
      t2 = tmid;
    else
      t1 = tmid;
  }
  cout << fixed << setprecision(12) << tmid << '\n';
  return 0;
}
