#include <bits/stdc++.h>
using namespace std;
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
void disp(T& x) {
  for (typename T::iterator it = x.begin(); it != x.end(); ++it)
    cout << *it << ' ';
  cout << endl;
}
struct pt {
  int x, w;
};
bool f(pt a, pt b) { return a.x + a.w < b.x + b.w; }
pt mas[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> mas[i].x >> mas[i].w;
  sort(mas, mas + n, f);
  int ans = 1;
  int last = 0;
  for (int i = 1; i < n; ++i)
    if (mas[i].x - mas[i].w >= mas[last].x + mas[last].w) {
      ans++;
      last = i;
    }
  cout << ans;
  return 0;
}
