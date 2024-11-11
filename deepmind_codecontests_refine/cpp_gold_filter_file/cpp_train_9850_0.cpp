#include <bits/stdc++.h>
using namespace std;
long long n, a[1005];
bool marked[1005];
bool lone() {
  int start = a[1];
  double best = -2e9 + 5;
  int lastpt = -1;
  for (int i = 2; i < n; i++) {
    if ((double)(a[i] - start) / (i - 1) >= best) {
      best = (double)(a[i] - start) / (i - 1);
      lastpt = i;
    }
  }
  assert(lastpt != -1);
  int on = 0;
  memset(marked, 0, sizeof(marked));
  for (int i = 0; i <= lastpt; i++) {
    if (best * (i - 1) + start == a[i]) {
      on++;
      marked[i] = true;
    }
  }
  if (on == n) return false;
  int prev = -1;
  for (int i = 0; i < n; i++) {
    if (!marked[i]) {
      if (prev != -1) {
        if ((double)(a[i] - a[prev]) / (i - prev) != best) {
          return false;
        }
      }
      prev = i;
    }
  }
  return true;
}
bool lone2() {
  int start = a[1];
  double best = 2e9 + 5;
  int lastpt = -1;
  for (int i = 2; i < n; i++) {
    if ((double)(a[i] - start) / (i - 1) <= best) {
      best = (double)(a[i] - start) / (i - 1);
      lastpt = i;
    }
  }
  assert(lastpt != -1);
  int on = 0;
  memset(marked, 0, sizeof(marked));
  for (int i = 0; i <= lastpt; i++) {
    if (best * (i - 1) + start == a[i]) {
      on++;
      marked[i] = true;
    }
  }
  if (on == n) return false;
  int prev = -1;
  for (int i = 0; i < n; i++) {
    if (!marked[i]) {
      if (prev != -1) {
        if ((double)(a[i] - a[prev]) / (i - prev) != best) {
          return false;
        }
      }
      prev = i;
    }
  }
  return true;
}
bool increasing() {
  int start = a[0];
  double best = -2e9 + 5;
  int lastpt = -1;
  for (int i = 1; i < n; i++) {
    if ((double)(a[i] - start) / i >= best) {
      best = (double)(a[i] - start) / i;
      lastpt = i;
    }
  }
  assert(lastpt != -1);
  int on = 0;
  memset(marked, 0, sizeof(marked));
  for (int i = 0; i <= lastpt; i++) {
    if (best * i + start == a[i]) {
      on++;
      marked[i] = true;
    }
  }
  if (on == n) return false;
  int prev = -1;
  for (int i = 0; i < n; i++) {
    if (!marked[i]) {
      if (prev != -1) {
        if ((double)(a[i] - a[prev]) / (i - prev) != best) {
          return false;
        }
      }
      prev = i;
    }
  }
  return true;
}
bool decreasing() {
  int start = a[0];
  double best = 2e9 + 5;
  int lastpt = -1;
  for (int i = 1; i < n; i++) {
    if ((double)(a[i] - start) / i <= best) {
      best = (double)(a[i] - start) / i;
      lastpt = i;
    }
  }
  assert(lastpt != -1);
  int on = 0;
  memset(marked, 0, sizeof(marked));
  for (int i = 0; i <= lastpt; i++) {
    if (best * i + start == a[i]) {
      on++;
      marked[i] = true;
    }
  }
  if (on == n) return false;
  int prev = -1;
  for (int i = 0; i < n; i++) {
    if (!marked[i]) {
      if (prev != -1) {
        if ((double)(a[i] - a[prev]) / (i - prev) != best) {
          return false;
        }
      }
      prev = i;
    }
  }
  return true;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (increasing() || decreasing() || lone() || lone2()) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
