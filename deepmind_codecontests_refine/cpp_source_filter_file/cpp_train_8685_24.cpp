#include <bits/stdc++.h>
using namespace std;
int a[105] = {0}, b[105] = {0};
void findr_1(int m) {
  if (m == 4) {
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    a[4] = 4;
  }
  if (m == 5) {
    a[1] = 2;
    a[2] = 2;
    a[3] = 2;
    a[4] = 2;
    a[5] = 3;
  }
  if (m == 6) {
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    a[5] = 3;
    a[6] = 3;
  }
  if (m == 7) {
    for (int i = 1; i <= 5; i++) a[i] = 1;
    a[6] = 2;
    a[7] = 4;
  }
  if (m == 8) {
    for (int i = 1; i <= 4; i++) a[i] = 1;
    a[5] = 2;
    a[6] = 2;
    a[7] = 2;
    a[8] = 3;
  }
  if (m == 9) {
    for (int i = 1; i <= 7; i++) a[i] = 1;
    a[8] = 3;
    a[9] = 3;
  }
  if (m == 10) {
    for (int i = 1; i <= 9; i++) a[i] = 1;
    a[10] = 4;
  }
  if (m == 11) {
    for (int i = 1; i <= 8; i++) a[i] = 1;
    a[9] = 2;
    a[10] = 2;
    a[11] = 3;
  }
}
void findr(int m) {
  if (m == 1) {
    a[1] = 13;
  } else if (m == 2) {
    a[1] = 5;
    a[2] = 12;
  } else if (m == 3) {
    a[1] = 3;
    a[2] = 4;
    a[3] = 12;
  } else if (m == 4) {
    a[1] = 4;
    a[2] = 5;
    a[3] = 8;
    a[4] = 8;
  } else if (5 <= m && m < 41) {
    for (int i = 4; i <= 11; i++) {
      if (m - i == 1) {
        findr_1(i);
        a[i + 1] = 12;
        return;
      }
      if (m - i == 9) {
        findr_1(i);
        for (int j = 1; j <= 9; j++) a[i + j] = 4;
        return;
      }
      if (m - i == 16) {
        findr_1(i);
        for (int j = 1; j <= 16; j++) a[i + j] = 3;
        return;
      }
      if (m - i == 23) {
        findr_1(i);
        for (int j = 1; j <= 14; j++) a[i + j] = 3;
        int curr = i + 14;
        for (int j = 1; j <= 3; j++) a[curr + j] = 2;
        curr += 3;
        for (int j = 1; j <= 6; j++) a[curr + j] = 1;
        return;
      }
      if (m - i == 31) {
        findr_1(i);
        for (int j = 1; j <= 10; j++) a[i + j] = 3;
        int curr = i + 10;
        for (int j = 1; j <= 11; j++) a[curr + j] = 2;
        curr += 11;
        for (int j = 1; j <= 10; j++) a[curr + j] = 1;
        return;
      }
    }
  } else {
    if (m % 3 == 0) {
      a[1] = 3;
      a[2] = 3;
      for (int i = 3; i <= 39 - (m - 42) / 3; i++) {
        a[i] = 2;
      }
      for (int i = 40 - (m - 42) / 3; i <= m; i++) {
        a[i] = 1;
      }
    }
    if (m % 3 == 1) {
      for (int i = 1; i <= 42 - (m - 43) / 3; i++) {
        a[i] = 2;
      }
      for (int i = 43 - (m - 43) / 3; i <= m; i++) {
        a[i] = 1;
      }
    }
    if (m % 3 == 2) {
      a[1] = 1;
      for (int i = 2; i <= 41 - (m - 41) / 3; i++) {
        a[i] = 2;
      }
      for (int i = 42 - (m - 41) / 3; i <= m; i++) {
        a[i] = 1;
      }
    }
    return;
  }
}
void findc_1(int n) {
  if (n == 4) {
    b[1] = 1;
    b[2] = 2;
    b[3] = 2;
    b[4] = 4;
  }
  if (n == 5) {
    b[1] = 2;
    b[2] = 2;
    b[3] = 2;
    b[4] = 2;
    b[5] = 3;
  }
  if (n == 6) {
    b[1] = 1;
    b[2] = 1;
    b[3] = 1;
    b[4] = 2;
    b[5] = 3;
    b[6] = 3;
  }
  if (n == 7) {
    for (int i = 1; i <= 5; i++) b[i] = 1;
    b[6] = 2;
    b[7] = 4;
  }
  if (n == 8) {
    for (int i = 1; i <= 4; i++) b[i] = 1;
    b[5] = 2;
    b[6] = 2;
    b[7] = 2;
    b[8] = 3;
  }
  if (n == 9) {
    for (int i = 1; i <= 7; i++) b[i] = 1;
    b[8] = 3;
    b[9] = 3;
  }
  if (n == 10) {
    for (int i = 1; i <= 9; i++) b[i] = 1;
    b[10] = 4;
  }
  if (n == 11) {
    for (int i = 1; i <= 8; i++) b[i] = 1;
    b[9] = 2;
    b[10] = 2;
    b[11] = 3;
  }
}
void findc(int n) {
  if (n == 1) {
    b[1] = 13;
  } else if (n == 2) {
    b[1] = 5;
    b[2] = 12;
  } else if (n == 3) {
    b[1] = 3;
    b[2] = 4;
    b[3] = 12;
  } else if (n == 4) {
    b[1] = 4;
    b[2] = 5;
    b[3] = 8;
    b[4] = 8;
  } else if (5 <= n && n < 41) {
    for (int i = 4; i <= 11; i++) {
      if (n - i == 1) {
        findc_1(i);
        b[i + 1] = 12;
        return;
      }
      if (n - i == 9) {
        findc_1(i);
        for (int j = 1; j <= 9; j++) b[i + j] = 4;
        return;
      }
      if (n - i == 16) {
        findc_1(i);
        for (int j = 1; j <= 16; j++) b[i + j] = 3;
        return;
      }
      if (n - i == 23) {
        findc_1(i);
        for (int j = 1; j <= 14; j++) b[i + j] = 3;
        int curr = i + 14;
        for (int j = 1; j <= 3; j++) b[curr + j] = 2;
        curr += 3;
        for (int j = 1; j <= 6; j++) b[curr + j] = 1;
        return;
      }
      if (n - i == 31) {
        findc_1(i);
        for (int j = 1; j <= 10; j++) b[i + j] = 3;
        int curr = i + 10;
        for (int j = 1; j <= 11; j++) b[curr + j] = 2;
        curr += 11;
        for (int j = 1; j <= 10; j++) b[curr + j] = 1;
        return;
      }
    }
  } else {
    if (n % 3 == 0) {
      b[1] = 3;
      b[2] = 3;
      for (int i = 3; i <= 39 - (n - 42) / 3; i++) {
        b[i] = 2;
      }
      for (int i = 40 - (n - 42) / 3; i <= n; i++) {
        b[i] = 1;
      }
    }
    if (n % 3 == 1) {
      for (int i = 1; i <= 42 - (n - 43) / 3; i++) {
        b[i] = 2;
      }
      for (int i = 43 - (n - 43) / 3; i <= n; i++) {
        b[i] = 1;
      }
    }
    if (n % 3 == 2) {
      b[1] = 1;
      for (int i = 2; i <= 41 - (n - 41) / 3; i++) {
        b[i] = 2;
      }
      for (int i = 42 - (n - 41) / 3; i <= n; i++) {
        b[i] = 1;
      }
    }
    return;
  }
}
int main(int argc, char *argv[]) {
  int m, n;
  cin >> m >> n;
  findr(m);
  findc(n);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i] * b[j] << " ";
    }
    cout << endl;
  }
  return EXIT_SUCCESS;
}
