#include <bits/stdc++.h>
using namespace std;
const int MAXN = -1;
long long X, d, val, DOS[65];
vector<long long> Ans;
void execute() {
  int t = 0;
  while (DOS[t + 1] - 1 <= X) t++;
  for (int i = (0); i < (int)(t); i++) Ans.push_back(val);
  X -= (DOS[t] - 1);
}
int main() {
  DOS[0] = 1;
  for (int i = (1); i < (int)(62); i++) DOS[i] = DOS[i - 1] * 2;
  while (scanf("%lld %lld", &X, &d) == 2) {
    val = 1;
    Ans.clear();
    while (X) {
      execute();
      val += d;
    }
    printf("%d\n", Ans.size());
    int n = Ans.size();
    for (int i = (0); i < (int)(n); i++) {
      if (i) printf(" ");
      printf("%d", Ans[i]);
    }
    puts("");
  }
  return 0;
}
