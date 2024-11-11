#include <bits/stdc++.h>
using namespace std;
long long a[200005], a1[1005];
int main() {
  long long i, j, k, l, n, m;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < 7; i += 2) {
    a1[i] = 31;
    if (i == 0) {
      a1[i + 1] = 28;
    } else if (i < 6) {
      a1[i + 1] = 30;
    }
  }
  for (i = 7; i < 12; i += 2) {
    a1[i] = 31;
    if (i < 12) {
      a1[i + 1] = 30;
    }
  }
  for (i = 12; i < 19; i += 2) {
    a1[i] = 31;
    if (i == 12) {
      a1[i + 1] = 28;
    } else if (i < 18) {
      a1[i + 1] = 30;
    }
  }
  for (i = 19; i < 24; i += 2) {
    a1[i] = 31;
    if (i < 24) {
      a1[i + 1] = 30;
    }
  }
  for (i = 24; i < 31; i += 2) {
    a1[i] = 31;
    if (i == 24) {
      a1[i + 1] = 29;
    } else if (i < 30) {
      a1[i + 1] = 30;
    }
  }
  for (i = 31; i < 36; i += 2) {
    a1[i] = 31;
    if (i < 36) {
      a1[i + 1] = 30;
    }
  }
  for (i = 36; i < 43; i += 2) {
    a1[i] = 31;
    if (i == 36) {
      a1[i + 1] = 28;
    } else if (i < 42) {
      a1[i + 1] = 30;
    }
  }
  for (i = 43; i < 48; i += 2) {
    a1[i] = 31;
    if (i < 48) {
      a1[i + 1] = 30;
    }
  }
  for (i = 48; i < 55; i += 2) {
    a1[i] = 31;
    if (i == 48) {
      a1[i + 1] = 28;
    } else if (i < 54) {
      a1[i + 1] = 30;
    }
  }
  for (i = 55; i < 60; i += 2) {
    a1[i] = 31;
    if (i < 60) {
      a1[i + 1] = 30;
    }
  }
  long long f = 0;
  for (i = 0; i < 60 - n; i++) {
    f = 0;
    for (j = i; j < i + n; j++) {
      if (a[f] == a1[j]) {
        f++;
      }
    }
    if (f == n) {
      break;
    }
  }
  if (f == n) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
