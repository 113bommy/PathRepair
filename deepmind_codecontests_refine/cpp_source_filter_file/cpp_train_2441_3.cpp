#include <bits/stdc++.h>
using namespace std;
void print_result(vector<pair<int, int> > r) {
  if (r.size() > 0) printf("%d ", r.size());
  for (int i = 0; i < r.size(); i++) {
    printf("%d %d ", r[i].first, r[i].second);
  }
  printf("\n");
}
void pipe(int m, int n, int type, int k) {
  if (type) {
    swap(m, n);
  }
  pair<int, int> p;
  vector<pair<int, int> > ans;
  if (k <= m) {
    for (int i = 1; i <= k - 1; i++) {
      ans.clear();
      for (int j = 1; j <= n; j++) {
        type == 0 ? p = make_pair(i, j) : p = make_pair(j, i);
        ans.push_back(p);
      }
      print_result(ans);
    }
    ans.clear();
    for (int i = k; i <= m; i++) {
      if (i % 2) {
        for (int j = 1; j <= n; j++) {
          type == 0 ? p = make_pair(i, j) : p = make_pair(j, i);
          ans.push_back(p);
        }
      } else {
        for (int j = n; j >= 1; j--) {
          type == 0 ? p = make_pair(i, j) : p = make_pair(j, i);
          ans.push_back(p);
        }
      }
    }
    print_result(ans);
  } else if (type == 0) {
    int i = 1, j = 1;
    int count = 0;
    while (i <= m && count < k - 1) {
      if (n % 2) {
        if (i % 2) {
          while (j < n - 1 && count < k - 1) {
            printf("2 %d %d %d %d\n", i, j, i, j + 1);
            count++;
            j += 2;
          }
        } else {
          while (j > 1 && count < k - 1) {
            printf("2 %d %d %d %d\n", i, j, i, j - 1);
            count++;
            j -= 2;
          }
        }
        if (i % 2 && count < k - 1) {
          printf("2 %d %d %d %d\n", i, j, i + 1, j);
          j = n - 1;
          count++;
          i++;
        } else if (i % 2 == 0 && count < k - 1) {
          j = 1;
          i++;
        }
        if (count == k - 1) break;
      } else {
        if (i % 2) {
          while (j <= n - 1 && count < k - 1) {
            printf("2 %d %d %d %d\n", i, j, i, j + 1);
            count++;
            j += 2;
          }
        } else {
          while (j > 1 && count < k - 1) {
            printf("2 %d %d %d %d\n", i, j - 1, i, j);
            count++;
            j -= 2;
          }
        }
        if (i % 2 && count < k - 1) {
          j = n;
          i++;
        } else if (i % 2 == 0 && count < k - 1) {
          j = 1;
          i++;
        }
        if (count == k - 1) break;
      }
    }
    ans.clear();
    while (i <= m) {
      if (j % 2) {
        while (j <= n) {
          p = make_pair(i, j);
          ans.push_back(p);
          j++;
        }
        j = n;
      } else {
        while (j >= 1) {
          p = make_pair(i, j);
          ans.push_back(p);
          j--;
        }
        j = 1;
      }
      i++;
    }
    print_result(ans);
  } else if (type == 1) {
    swap(m, n);
    int i = 1, j = 1;
    int count = 0;
    while (i <= n && count < k - 1) {
      if (m % 2) {
        if (i % 2) {
          while (j < m - 1 && count < k - 1) {
            printf("2 %d %d %d %d\n", j, i, j + 1, i);
            count++;
            j += 2;
          }
        } else {
          while (j > 1 && count < k - 1) {
            printf("2 %d %d %d %d\n", j - 1, i, j, i);
            count++;
            j -= 2;
          }
        }
        if (i % 2 && count < k - 1) {
          printf("2 %d %d %d %d\n", j, i, j, i + 1);
          j = m - 1;
          count++;
          i++;
        } else if (i % 2 == 0 && count < k - 1) {
          j = 1;
          i++;
        }
        if (count == k - 1) break;
      } else {
        if (i % 2) {
          while (j <= m - 1 && count < k - 1) {
            printf("2 %d %d %d %d\n", j, i, j + 1, i);
            count++;
            j += 2;
          }
        } else {
          while (j > 1 && count < k - 1) {
            printf("2 %d %d %d %d\n", j - 1, i, j, i);
            count++;
            j -= 2;
          }
        }
        if (i % 2 && count < k - 1) {
          j = m;
          i++;
        } else if (i % 2 == 0 && count < k - 1) {
          j = 1;
          i++;
        }
        if (count == k - 1) break;
      }
    }
    ans.clear();
    while (i <= n) {
      if (i % 2) {
        while (j <= m) {
          p = make_pair(j, i);
          ans.push_back(p);
          j++;
        }
        j = m;
      } else {
        while (j >= 1) {
          p = make_pair(j, i);
          ans.push_back(p);
          j--;
        }
        j = 1;
      }
      i++;
    }
    print_result(ans);
  }
}
int main() {
  int m, n, k;
  while (scanf("%d %d %d", &m, &n, &k) == 3) {
    if (m <= n) {
      pipe(m, n, 0, k);
    } else {
      pipe(m, n, 1, k);
    }
  }
  return 0;
}
