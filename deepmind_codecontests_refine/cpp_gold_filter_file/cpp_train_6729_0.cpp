#include <bits/stdc++.h>
using namespace std;
template <typename T, typename C>
ostream &operator<<(ostream &os, pair<T, C> x) {
  return os << "<" << x.first << ", " << x.second << ">";
}
template <typename T>
auto operator<<(ostream &os, T x) ->
    typename enable_if<is_same<decltype(x.begin()), decltype(x.end())>::value &&
                           !is_same<T, string>::value,
                       ostream &>::type {
  os << "{";
  int cou = 0;
  for (auto c : x) {
    if (cou++) os << ", ";
    os << c;
  }
  return os << "}";
}
template <typename T>
string strmask(T r) {
  string ans;
  for (int i = 0; i < (8 * (int)sizeof(T)); i++) {
    ans += '0' + !!(((T)1 << i) & r);
    if (i % 5 == 4) ans += '.';
  }
  return ans;
}
void show(const vector<int> &x) {
  if (x.empty())
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 1; i <= (((int)x.size()) - 1); i++) printf("%d ", x[i]);
    printf("\n");
  }
}
const int LOG = 17;
const int MN = 1 << LOG;
int ans[MN];
int larg(int n) {
  int pow = 1;
  while (pow <= n) pow *= 2;
  return pow;
}
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 10) {
    vector<int> all;
    for (int i = 0; i <= (n); i++) all.push_back(i);
    vector<int> p1, p2;
    do {
      bool zero = false, nonzero = false;
      bool fixed = false;
      for (int i = 1; i <= (n); i++) {
        if (i & all[i])
          nonzero = true;
        else
          zero = true;
        if (all[i] == i) fixed = true;
      }
      if (!zero && !fixed) p1 = all;
      if (!nonzero && !fixed) p2 = all;
    } while (next_permutation(1 + all.begin(), all.end()));
    show(p2);
    show(p1);
    return 0;
  }
  if (n % 2)
    printf("NO\n");
  else {
    printf("YES\n");
    int nn = n;
    while (nn > 0) {
      int pow = larg(nn);
      if (0)
        cout << "pow"
             << " = " << (pow) << ' ' << "nn"
             << " = " << (nn) << ' ' << endl;
      for (int i = nn; pow - i - 1 <= nn; --i) {
        ans[i] = pow - i - 1;
        if (0)
          cout << "set "
               << "ans"
               << "["
               << "i"
               << "] = "
               << "ans"
               << "[" << i << "] = " << ans[i] << ' ' << endl;
      }
      nn = pow - nn - 2;
    }
    for (int i = 1; i <= (n); i++) {
      printf("%d ", ans[i]);
      assert((i & ans[i]) == 0);
    }
    printf("\n");
  }
  if ((n & (n - 1)) == 0) {
    printf("NO\n");
  } else {
    printf("YES\n");
    vector<int> type[LOG];
    for (int i = 1; i <= (n); i++) {
      if (i == 7)
        type[0].push_back(i);
      else {
        int highest = 0;
        while (1 << (highest + 1) <= i) highest++;
        type[highest].push_back(i);
      }
    }
    for (int i = 0; i < (LOG); i++) {
      if (0)
        cout << "type"
             << "["
             << "i"
             << "] = "
             << "type"
             << "[" << i << "] = " << type[i] << ' ' << endl;
      for (int k = 0; k < (((int)type[i].size())); k++) {
        ans[type[i][k]] = type[i][(k + 1) % ((int)type[i].size())];
      }
    }
    for (int i = 1; i <= (n); i++) {
      printf("%d ", ans[i]);
      assert(i & ans[i]);
    }
    printf("\n");
  }
}
