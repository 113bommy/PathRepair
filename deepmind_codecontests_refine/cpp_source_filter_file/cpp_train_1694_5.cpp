#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int maxn = 1e3 + 5;
queue<int> Q;
char s1[maxn], s2[maxn];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> (s1 + 1);
    cin >> (s2 + 1);
    int op = 0;
    for (int i = (1); i < (n); ++i) {
      if (s1[i] == '1') {
        int temp = i;
        while (s1[i + 1] == '1' && i < n) {
          s1[i] = '0';
          i++;
        }
        if (temp == 1) {
          op++;
          Q.push(i);
          s1[i] = '0';
        } else {
          op += 2;
          Q.push(temp - 1);
          Q.push(i);
          s1[i] = '0';
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      if (s2[i] == '1') {
        int temp = i;
        while (s2[i - 1] == '1' && i >= 0) {
          i--;
        }
        if (i == 1) {
          op++;
          Q.push(temp);
        } else {
          op += 2;
          Q.push(temp);
          Q.push(i - 1);
        }
      }
    }
    printf("%d", op);
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      printf(" %d", x);
    }
    printf("\n");
  }
  return 0;
}
