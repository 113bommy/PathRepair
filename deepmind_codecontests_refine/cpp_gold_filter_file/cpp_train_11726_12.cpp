#include <bits/stdc++.h>
using namespace std;
const long long INF_MAX = 1e9, MOD = 1000000007;
const long long INF = 1e18;
bitset<10000> u;
vector<int> v_a, v_b;
int a[1000000], ptr, h, n;
bool b;
int main() {
  cin >> h;
  for (int i = 0; i <= h; i++) {
    scanf("%d", &a[i]);
    n += a[i];
    if (i && a[i - 1] > 1 && a[i] > 1) b = true;
  }
  int fst = 0, lst = 0;
  v_a.push_back(0);
  v_b.push_back(0);
  for (int i = 1; i <= h; i++) {
    int n_f = INF_MAX, n_s = -INF_MAX;
    for (int j = 0; j < a[i]; j++) {
      ptr++;
      v_a.push_back(fst);
      if (j == a[i] - 1)
        v_b.push_back(lst);
      else
        v_b.push_back(fst);
      n_f = min(n_f, ptr);
      n_s = max(n_s, ptr);
    }
    fst = n_f;
    lst = n_s;
  }
  if (!b)
    cout << "perfect";
  else {
    cout << "ambiguous\n";
    cout << 0 << ' ';
    for (int i = 1; i < v_a.size(); i++) printf("%d ", v_a[i] + 1);
    putchar('\n');
    cout << 0 << ' ';
    for (int i = 1; i < v_a.size(); i++) printf("%d ", v_b[i] + 1);
  }
}
