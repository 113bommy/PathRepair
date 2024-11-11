#include <bits/stdc++.h>
using namespace std;
const int DBG = 0, INF = int(1e9);
int main() {
  ios_base::sync_with_stdio(0);
  cout.setf(ios::fixed);
  int k, X, n, m;
  cin >> k >> X >> n >> m;
  auto check = [](int n, int ac, char first, char last) {
    if (n == 1) return first != last;
    if (n % 2 == 0 && ac == n / 2) return first == 'A' && last == 'C';
    if (n % 2 == 1 && ac == n / 2) return first == 'A' || last == 'C';
    return true;
  };
  auto gen = [](int n, int ac, char first, char last) {
    string res = "";
    if (n == 1) return res += first;
    if (n % 2 == 0 && ac == n / 2) {
      assert(first == 'A' && last == 'C');
      for (int i = 0; i < n / 2; ++i) res += "AC";
      return res;
    }
    if (n % 2 == 1 && ac == n / 2) {
      if (first == 'A') {
        for (int i = 0; i < n / 2; ++i) res += "AC";
        res += last;
        return res;
      }
      assert(last == 'C');
      res += first;
      for (int i = 0; i < n / 2; ++i) res += "AC";
      return res;
    }
    res += first;
    for (int i = 0; i < ac * 2 + (n % 2); ++i)
      if (i % 2 == 0)
        res += 'A';
      else
        res += 'C';
    while (res.size() + 1 < n) res += 'B';
    res += last;
    return res;
  };
  for (int first_ac = 0; first_ac <= n / 2; ++first_ac)
    for (char first_let0 = 'A'; first_let0 <= 'C'; ++first_let0)
      for (char first_letn = 'A'; first_letn <= 'C'; ++first_letn) {
        if (!check(n, first_ac, first_let0, first_letn)) continue;
        for (int sec_ac = 0; sec_ac <= m / 2; ++sec_ac)
          for (char sec_let0 = 'A'; sec_let0 <= 'C'; ++sec_let0)
            for (char sec_letn = 'A'; sec_letn <= 'C'; ++sec_letn) {
              if (!check(m, sec_ac, sec_let0, sec_letn)) continue;
              auto good = [k, X](int first_ac, char first_let0, char first_letn,
                                 int sec_ac, char sec_let0, char sec_letn) {
                for (int cur = 2; cur < k; ++cur) {
                  int tmp_ac = sec_ac, tmp_let0 = sec_let0, tmp_letn = sec_letn;
                  sec_ac = first_ac + sec_ac +
                           (first_letn == 'A' && sec_let0 == 'C');
                  sec_let0 = first_let0;
                  sec_letn = sec_letn;
                  first_ac = tmp_ac, first_let0 = tmp_let0,
                  first_letn = tmp_letn;
                  if (sec_ac > X) return false;
                }
                return sec_ac == X;
              };
              if (good(first_ac, first_let0, first_letn, sec_ac, sec_let0,
                       sec_letn)) {
                cout << gen(n, first_ac, first_let0, first_letn) << endl
                     << gen(m, sec_ac, sec_let0, sec_letn) << endl;
                return 0;
              }
            }
      }
  cout << "Happy new year!\n";
  return 0;
}
