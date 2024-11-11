#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
inline long long int powe(long long int a) { return a * a * a; }
pair<long long int, long long int> best = make_pair(0, 0);
void calc(long long int num, long long int st, long long int subt) {
  if (num == 0) {
    best = max(best, make_pair(st, subt));
    return;
  }
  long long int x = 1;
  while (powe(x + 1) <= num) x++;
  calc(num - powe(x), st + 1, subt + powe(x));
  calc(powe(x) - 1 - powe(x - 1), st + 1, subt + powe(x - 1));
}
int main() {
  long long int q;
  cin >> q;
  calc(q, 0, 0);
  cout << best.first << ' ' << best.second << '\n';
  return 0;
}
