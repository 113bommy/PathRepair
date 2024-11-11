#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> d[100000 + 10];
bool h[100000 + 10];
int pr[100000 + 10];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 2; 2 * i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      d[j].push_back(i);
    }
  }
  while (m--) {
    char c;
    cin >> c;
    if (c == '+') {
      int i;
      cin >> i;
      if (h[i] == true) {
        printf("Already on\n");
      } else {
        bool flag = true;
        for (__typeof(d[i].begin()) it = d[i].begin(); it != d[i].end(); it++) {
          if (pr[*it] == 0)
            continue;
          else {
            flag = false;
            printf("Conflict with %d\n", pr[*it]);
            break;
          }
        }
        if (flag == true) {
          for (__typeof(d[i].begin()) it = d[i].begin(); it != d[i].end();
               it++) {
            pr[*it] = i;
          }
          h[i] = true;
          printf("Success\n");
        }
      }
    }
    if (c == '-') {
      int i;
      scanf("%d", &i);
      if (h[i] == false) {
        printf("Already off\n");
      } else {
        for (__typeof(d[i].begin()) it = d[i].begin(); it != d[i].end(); it++) {
          pr[*it] = 0;
        }
        h[i] = false;
        printf("Success\n");
      }
    }
  }
}
