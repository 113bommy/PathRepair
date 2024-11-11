#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
int n, q;
set<int> s1, s2;
int w[MAXN];
void Insert(int a) {
  if (s1.count(a)) {
    w[a]++;
    if (w[a] >= 4) s1.erase(a), s2.insert(a);
  } else if (s2.count(a))
    w[a]++;
  else {
    w[a]++;
    if (w[a] >= 2) s1.insert(a);
  }
}
void Delete(int a) {
  if (s1.count(a)) {
    w[a]--;
    if (w[a] < 2) s1.erase(a);
  } else if (s2.count(a)) {
    w[a]--;
    if (w[a] < 4) s2.erase(a), s1.insert(a);
  } else
    w[a]--;
}
int main() {
  scanf("%d", &n);
  for (int a, i = 1; i <= n; i++) {
    scanf("%d", &a);
    Insert(a);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    char op;
    int x;
    op = getchar();
    while (op != '+' && op != '-') op = getchar();
    scanf("%d", &x);
    if (op == '+') Insert(x);
    if (op == '-') Delete(x);
    if (s2.size() >= 2)
      puts("YES");
    else if (s2.size() == 1) {
      if (w[*s2.begin()] - 4 >= 4)
        puts("YES");
      else if (w[*s2.begin()] - 4 >= 2 && s1.size() >= 1)
        puts("YES");
      else if (s1.size() > 2)
        puts("YES");
      else
        puts("NO");
    } else
      puts("NO");
  }
}
