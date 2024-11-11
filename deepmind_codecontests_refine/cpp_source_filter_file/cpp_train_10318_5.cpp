#include <bits/stdc++.h>
using namespace std;
int b[105];
int vis[105];
int main() {
  int n;
  scanf("%d", &n);
  int a[105];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
  }
  int ans1 = 0;
  int ans2 = 0;
  int jo = 1;
  int mm = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    if (b[x] > 0) {
      if (b[x] <= 2) {
        if (jo == 1) {
          vis[i] = 1;
          jo = -1;
          ans1++;
          if (b[x] == 2) {
            for (int j = i + 1; j <= n; j++) {
              if (a[i] == x) {
                vis[i] = 1;
                jo = -1;
                ans1++;
                break;
              }
            }
          }
        } else {
          vis[i] = -1;
          jo = 1;
          ans2++;
          if (b[x] == 2) {
            for (int j = i + 1; j <= n; j++) {
              if (a[i] == x) {
                vis[i] = -1;
                jo = 1;
                ans2++;
                break;
              }
            }
          }
        }
        b[x] = 0;
      } else {
        mm++;
      }
    }
  }
  if (ans1 == ans2) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (vis[i] == 1) {
        cout << "B";
      } else {
        cout << "A";
      }
    }
  } else {
    if (mm == 0) {
      cout << "NO" << endl;
    } else {
      if (ans1 > ans2) {
        for (int i = 0; i < n; i++) {
          if (b[a[i]] > 2) {
            vis[i] = -1;
            break;
          }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
          if (vis[i] == 1 || vis[i] == 0) {
            cout << "B";
          } else {
            cout << "A";
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (b[a[i]] > 2) {
            vis[i] = 1;
            break;
          }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
          if (vis[i] == 1) {
            cout << "B";
          } else {
            cout << "A";
          }
        }
      }
    }
  }
  return 0;
}
