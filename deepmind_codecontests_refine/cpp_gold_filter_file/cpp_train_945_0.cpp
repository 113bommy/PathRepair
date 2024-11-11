#include <bits/stdc++.h>
using namespace std;
int ara[500008];
set<int> s;
set<int>::iterator it;
int n;
void check(int num) {
  for (int i = 1; i < n; i++) {
    if (!(ara[i] % num == 0 || ara[n + i] % num == 0)) {
      return;
    }
  }
  cout << num << endl;
  exit(0);
}
int primefactor(int num) {
  int i;
  for (i = 2; i <= num / i; i++) {
    bool flag = 0;
    while (num % i == 0) {
      num /= i;
      if (!flag) {
        check(i);
      }
      flag = 1;
    }
  }
  if (num > 1) {
    check(num);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &ara[i], &ara[n + i]);
  }
  primefactor(ara[0]);
  primefactor(ara[n]);
  cout << "-1" << endl;
  return 0;
}
