#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  vector<int> num;
  int c = 0;
  while (num.size() < 4 && c <= 9) {
    for (int i = 0; i < 4; i++) printf("%d", c);
    puts("");
    fflush(stdout);
    int a, b;
    scanf("%d%d", &a, &b);
    if (b > 0) num.push_back(c);
    c++;
  }
  if (num.size() < 4) return 0;
  do {
    for (int i = 0; i < 4; i++) printf("%d", num[i]);
    puts("");
    fflush(stdout);
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 4) break;
  } while (next_permutation(num.begin(), num.end()));
  string str = "";
  for (int i = 0; i < 4; i++) str += (num[i] + '0');
  return 0;
}
