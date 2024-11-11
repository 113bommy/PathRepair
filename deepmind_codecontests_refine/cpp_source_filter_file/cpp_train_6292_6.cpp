#include <bits/stdc++.h>
using namespace std;
int main() {
  string num;
  int k;
  while (cin >> num >> k) {
    int c = 0;
    while (k) {
      if (k >= num.size() - 1) {
        int i;
        char maxn = '0';
        int maxx = 0;
        for (i = c; i < num.size(); i++) {
          if (num[i] >= maxn) {
            maxn = num[i];
            maxx = i;
          }
        }
        for (i = maxx; i > c; i--) {
          char a;
          a = num[i];
          num[i] = num[i - 1];
          num[i - 1] = a;
          k--;
        }
        c++;
      } else {
        int i;
        char maxn = '0';
        int maxx = 0;
        for (i = c; i < c + k + 1; i++) {
          if (num[i] >= maxn) {
            maxn = num[i];
            maxx = i;
          }
        }
        for (i = maxx; i > c; i--) {
          char a;
          a = num[i];
          num[i] = num[i - 1];
          num[i - 1] = a;
          k--;
        }
        c++;
      }
      if (c >= num.size()) break;
    }
    cout << num << endl;
  }
  return 0;
}
