#include <bits/stdc++.h>
using namespace std;
struct node {
  int a;
  int b;
  int c;
  int d;
};
bool cmp(const node &first, const node &sec) {
  if (first.a != sec.a) return first.a < sec.a;
  return first.b < sec.b;
}
bool operator<(const node &left, const node &right) { return left.b > right.b; }
int n, k, arr[50], brr[50], crr[50], i, j, i1, i2, j2, i3, j3;
int reversey(int x, int y) {
  int i;
  for (i = 1; i <= n; i++) arr[i] = brr[i];
  for (i = 1; i < x; i++) brr[i] = arr[i];
  for (i = y + 1; i <= n; i++) brr[i] = arr[i];
  int l = x;
  for (i = y; i >= x; i--) {
    brr[l] = arr[i];
    l++;
  }
  return 0;
}
double inver() {
  int i, j;
  double r = 0;
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (brr[i] > brr[j]) r++;
    }
  }
  return r;
}
void call() {
  int i;
  for (i = 1; i <= n; i++) brr[i] = crr[i];
}
double ans;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> crr[i];
  if (k == 1) {
    ans = 0;
    for (i = 1; i <= n; i++) {
      for (j = i; j <= n; j++) {
        call();
        reversey(i, j);
        ans += inver();
      }
    }
    double n1 = n;
    double x = n1 * (n1 - 1) / 2 + n1;
    printf("%0.10lf", ans / x);
  }
  if (k == 2) {
    for (i = 1; i <= n; i++) {
      for (j = i; j <= n; j++) {
        for (int i1 = 1; i1 <= n; i1++) {
          for (int j1 = i1; j1 <= n; j1++) {
            call();
            reversey(i, j);
            reversey(i1, j1);
            ans += inver();
          }
        }
      }
    }
    double n1 = n;
    double x = n1 * (n1 - 1) / 2 + n1;
    ans /= x;
    ans /= x;
    printf("%0.10lf", ans);
  }
  if (k == 3) {
    for (i = 1; i <= n; i++) {
      for (j = i; j <= n; j++) {
        for (int i1 = 1; i1 <= n; i1++) {
          for (int j1 = i1; j1 <= n; j1++) {
            for (int i2 = 1; i2 <= n; i2++) {
              for (int j2 = i2; j2 <= n; j2++) {
                call();
                reversey(i, j);
                reversey(i1, j1);
                reversey(i2, j2);
                ans += inver();
              }
            }
          }
        }
      }
    }
    double n1 = n;
    double x = n1 * (n1 - 1) / 2 + n1;
    ans /= x;
    ans /= x;
    ans /= x;
    printf("%0.10lf", ans);
  }
  if (k == 4) {
    for (i = 1; i <= n; i++) {
      for (j = i; j <= n; j++) {
        for (int i1 = 1; i1 <= n; i1++) {
          for (int j1 = i1; j1 <= n; j1++) {
            for (int i2 = 1; i2 <= n; i2++) {
              for (int j2 = i2; j2 <= n; j2++) {
                for (int i3 = 1; i3 <= n; i3++) {
                  for (int j3 = i3; j3 <= n; j3++) {
                    call();
                    reversey(i, j);
                    reversey(i1, j1);
                    reversey(i2, j2);
                    reversey(i3, j3);
                    ans += inver();
                  }
                }
              }
            }
          }
        }
      }
    }
    double n1 = n;
    double x = n1 * (n1 - 1) / 2 + n1;
    ans /= x;
    ans /= x;
    ans /= x;
    ans /= x;
    printf("%0.10lf", ans);
  }
  return 0;
}
