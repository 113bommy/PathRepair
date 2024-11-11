#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
const int mod = 1000000007;
int n, m;
vector<int> grid[100000 + 7], rpat, cpat;
int get_num(int r, int c) { return (r - 1) * m + c; }
int main() {
  int mx, mn, i, j, k;
  scanf("%d %d", &n, &m);
  mx = max(n, m), mn = min(n, m);
  if (mx == 1) {
    puts("YES\n1");
    return 0;
  }
  if (n == 3 and m == 3) {
    puts("YES\n6 1 8\n7 5 3\n2 9 4");
    return 0;
  }
  if (mx <= 3) {
    puts("NO");
    return 0;
  }
  if (n == 2 and m == 4) {
    printf("YES\n5 4 7 2\n3 6 1 8\n");
    return 0;
  }
  if (n == 4 and m == 2) {
    printf("YES\n5 3\n4 6\n7 1\n2 8\n");
    return 0;
  }
  for (i = 1; 2 * i <= mx; i++) {
    rpat.push_back(mx / 2 + i);
    rpat.push_back(i);
  }
  if (mx % 2) rpat.push_back(mx);
  for (i = 1; 2 * i <= mn; i++) {
    cpat.push_back(mn / 2 + i);
    cpat.push_back(i);
  }
  if (mn % 2) cpat.push_back(mn);
  if (mn <= 3) {
    puts("YES");
    for (i = 0; i < mn; i++) {
      cpat = rpat;
      if (i == 1) {
        if (mx % 2 == 0) swap(cpat[mx - 1], cpat[mx - 3]);
        int tmp = cpat[0];
        for (j = 0; j < mx - 1; j++) cpat[j] = cpat[j + 1];
        cpat[j] = tmp;
      }
      grid[i] = cpat;
    }
    if (n >= m) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          printf("%d ", get_num(grid[j][i], j + 1));
        }
        puts("");
      }
    } else {
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          printf("%d ", get_num(i + 1, grid[i][j]));
        }
        puts("");
      }
    }
    return 0;
  }
  puts("YES");
  if (n >= m) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        printf("%d ", get_num(rpat[i], cpat[j]));
      }
      puts("");
    }
  } else {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        printf("%d ", get_num(cpat[i], rpat[j]));
      }
      puts("");
    }
  }
  return 0;
}
