#include <bits/stdc++.h>
using namespace std;
long long n;
long long l;
long long r;
long long p;
long long k;
void run() {
  l = max(1ll, l - k);
  r = min(n, r + k);
}
int lim;
int gue;
bool ask(long long l, long long r) {
  cout << l << ' ' << r << endl;
  fflush(stdout);
  string s;
  cin >> s;
  if (s == "Yes") {
    if (l == r) {
      exit(0);
    }
    return true;
  } else if (s == "No") {
    return false;
  }
  exit(0);
}
void limit() {
  lim++;
  long long m = (l + r) / 2;
  if (ask(l, m)) {
    r = m;
  } else {
    l = m + 1;
  }
}
void guess() {
  gue++;
  long long c = l + rand() % (r - l + 1);
  ask(c, c);
}
int main() {
  cin >> n >> k;
  srand(time(0));
  l = 1;
  r = n;
  p = 1000000000000007LL % n + 1;
  for (;;) {
    run();
    if ((r - l) > 50) {
      limit();
    } else {
      guess();
    }
  }
}
