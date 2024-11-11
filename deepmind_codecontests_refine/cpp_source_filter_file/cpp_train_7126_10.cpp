#include <bits/stdc++.h>
using namespace std;
vector<long long> ans;
vector<pair<long long, long long> > Rec;
int check(string second) {
  int i, l;
  l = second.length();
  for (i = 0; i < l / 2; i++) {
    if (second[i] != second[l - 1 - i]) return 0;
  }
  return 1;
}
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
vector<int> num, val;
set<int> A, B, tmp;
int main() {
  int n, i, j, k, a, b, flag = 0;
  scanf("%d %d %d", &n, &a, &b);
  num.resize(n);
  val.resize(n);
  for (i = 0; i < n; i++) {
    cin >> num[i];
    val[i] = num[i];
  }
  sort(num.begin(), num.end());
  for (i = 0; i < n; i++) {
    if (binary_search(num.begin(), num.end(), a - val[i])) {
      A.insert(val[i]);
      A.insert(a - val[i]);
    }
  }
  for (i = 0; i < n; i++) {
    if (A.find(val[i]) == A.end()) tmp.insert(val[i]);
  }
  while (!tmp.empty()) {
    int x = *tmp.begin();
    int y = b - x;
    if (tmp.find(y) == tmp.end()) {
      if (A.find(y) == A.end()) {
        printf("NO\n");
        return 0;
      }
      A.erase(y);
      A.erase(a - y);
      if (a - y != y) tmp.insert(a - y);
    }
    B.insert(x);
    B.insert(y);
    tmp.erase(x);
    tmp.erase(y);
  }
  printf("YES\n");
  for (i = 0; i < n; i++) {
    if (A.find(val[i]) == A.end()) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
  return 0;
}
