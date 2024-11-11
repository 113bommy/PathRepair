#include <bits/stdc++.h>
using namespace std;
struct t {
  char c;
  int a, b;
  t(char c, int a, int b) : c(c), a(a), b(b) {}
  t() {}
};
int n;
vector<t> e;
double temp;
double t0 = 1000;
double gen_rand() {
  int x = rand() + 1, y = rand() + 1;
  x %= y;
  return x / (double)y;
}
int get_ans() {
  int r = 0, b = 0;
  int R = 0, B = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int need =
        max(max(0, max(0, e[i].a - R) - r), max(0, max(0, e[i].b - B) - b));
    ans += need;
    r -= max(0, max(0, e[i].a - R));
    b -= max(0, max(0, e[i].b - B));
    r += need;
    b += need;
    ans++;
    if (e[i].c == 'R') {
      R++;
    } else {
      B++;
    }
  }
  return ans;
}
int main() {
  srand(time(NULL));
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    int r, b;
    cin >> c >> r >> b;
    e.push_back({c, r, b});
  }
  random_shuffle(e.begin(), e.end());
  temp = t0;
  int ans = INT_MAX;
  for (int qwe = 0; qwe < 100000; ++qwe) {
    int cur = get_ans();
    ans = min(ans, cur);
    vector<t> was = e;
    for (int i = 0; i < n * temp / t0; i++) {
      swap(e[rand() % n], e[rand() % n]);
    }
    int now = get_ans();
    ans = min(ans, now);
    if (now < cur) {
      cur = now;
    } else {
      double go = exp(-(now - cur) / temp);
      if (gen_rand() <= go) {
        cur = now;
      } else {
        e = was;
      }
    }
    temp *= 0.999;
  }
  cout << ans << endl;
}
