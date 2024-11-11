#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, i = 0, j = 0, k = 0, l = 0, m = 0, sum = 0, x = 0, y = 0, z = 0,
               p;
  cin >> n;
  int a[n][n], b[n][n], c[n][n], d[n][n];
  char ad[n][n], bd[n][n], cd[n][n], dd[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> ad[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> bd[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> cd[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> dd[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = ad[i][j] - '0';
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      b[i][j] = bd[i][j] - '0';
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = cd[i][j] - '0';
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      d[i][j] = dd[i][j] - '0';
    }
  }
  int arr[n][n], brr[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          arr[i][j] = 1;
        } else {
          arr[i][j] = 0;
        }
      } else {
        if (j % 2 == 0) {
          arr[i][j] = 0;
        } else {
          arr[i][j] = 1;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          brr[i][j] = 0;
        } else {
          brr[i][j] = 1;
        }
      } else {
        if (j % 2 == 0) {
          brr[i][j] = 1;
        } else {
          brr[i][j] = 0;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      x += abs(arr[i][j] - a[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - b[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - c[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - d[i][j]);
    }
  }
  m = x + y;
  y = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - c[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - b[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - d[i][j]);
    }
  }
  m = min(m, x + y);
  y = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - d[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - b[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - c[i][j]);
    }
  }
  m = min(m, x + y);
  y = 0;
  x = 0;
  y = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      x += abs(brr[i][j] - a[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - b[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - c[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - d[i][j]);
    }
  }
  m = min(m, x + y);
  y = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - c[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - b[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - d[i][j]);
    }
  }
  m = min(m, x + y);
  y = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(brr[i][j] - d[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - b[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      y += abs(arr[i][j] - d[i][j]);
    }
  }
  m = min(m, x + y);
  y = 0;
  cout << m;
  return 0;
}
