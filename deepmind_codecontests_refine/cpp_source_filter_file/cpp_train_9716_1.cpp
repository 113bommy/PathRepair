#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
int n, m, acnt, bcnt;
map<int, int> a, b;
int good[N], t[N];
char c[N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin.ignore();
    scanf("%c%d", &c[i], &t[i]);
    switch (c[i]) {
      case '+':
        a[t[i]]++;
        acnt++;
        break;
      case '-':
        b[t[i]]++;
        bcnt++;
        break;
    }
  }
  int all = 0;
  for (int i = 1; i <= n; i++) {
    int liars = 0;
    liars += acnt - a[i] + b[i];
    if (liars == n - m) {
      good[i] = 1;
      all++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (c[i] == '+') {
      if (!good[t[i]])
        puts("Lie");
      else if (all > 1)
        puts("Not defined");
      else
        puts("True");
    }
    if (c[i] == '-') {
      if (good[t[i]]) {
        if (all == 1)
          puts("Lie");
        else
          puts("Not defined");
      } else
        puts("True");
    }
  }
  return 0;
}
