#include <bits/stdc++.h>
using namespace std;
int like[1 << 7];
int main() {
  int n;
  cin >> n;
  map<string, int> hero;
  for (int i = 0; i < (n); ++i) {
    string a, b, c;
    cin >> a >> c >> b;
    int x, y;
    if (hero.count(a) == 0) hero[a] = hero.size() - 1;
    if (hero.count(b) == 0) hero[b] = hero.size() - 1;
    x = hero[a];
    y = hero[b];
    for (int mk = 0; mk < (((1) << (7))); ++mk)
      if ((((1) << (x)) & mk) && (((1) << (y)) & mk)) {
        like[mk]++;
      }
  }
  int diff = INT_MAX, max_like = 0;
  int a, b, c;
  cin >> a >> b >> c;
  for (int s1 = 0; s1 < (((1) << (7))); ++s1)
    for (int s2 = 0; s2 < (((1) << (7))); ++s2)
      if (s1 && s2 && (0 == (s1 & s2)) && (s1 ^ s2) != ((1) << (7)) - 1) {
        int s3 = (((1) << (7)) - 1) ^ (s1 | s2);
        assert(s3);
        int expe[] = {a / __builtin_popcount((s1)),
                      b / __builtin_popcount((s2)),
                      c / __builtin_popcount((s3))};
        pair<int, int> cur = make_pair(
            *max_element(expe, expe + 3) - *min_element(expe, expe + 3),
            -like[s1] - like[s2] - like[s3]);
        if (cur < make_pair(diff, -max_like)) {
          diff = cur.first;
          max_like = -cur.second;
        }
      }
  cout << diff << " " << max_like << endl;
  return 0;
}
