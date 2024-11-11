#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt[10001] = {0};
  int n;
  cin >> n;
  int a1[6], a2[6], a3[6];
  if (n == 1) {
    for (int i = 0; i < 6; i++) {
      cin >> a1[i];
      cnt[a1[i]]++;
    }
    for (int i = 1; i <= 9; i++) {
      if (cnt[i] == 0) {
        cout << i - 1;
        return 0;
      }
    }
  }
  if (n == 2) {
    for (int i = 0; i < 6; i++) {
      cin >> a1[i];
      cnt[a1[i]]++;
    }
    for (int i = 0; i < 6; i++) {
      cin >> a2[i];
      cnt[a2[i]]++;
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        int x = a1[i] * 10 + a2[j];
        int y = a2[j] * 10 + a1[i];
        cnt[x]++;
        cnt[y]++;
      }
    }
    for (int i = 1;; i++) {
      if (cnt[i] == 0) {
        cout << i - 1;
        return 0;
      }
    }
  }
  if (n == 3) {
    for (int i = 0; i < 6; i++) {
      cin >> a1[i];
      cnt[a1[i]]++;
    }
    for (int i = 0; i < 6; i++) {
      cin >> a2[i];
      cnt[a2[i]]++;
    }
    for (int i = 0; i < 6; i++) {
      cin >> a3[i];
      cnt[a3[i]]++;
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        int x = a1[i] * 10 + a2[j];
        int y = a2[j] * 10 + a1[i];
        cnt[x]++;
        cnt[y]++;
      }
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        int x = a1[i] * 10 + a3[j];
        int y = a3[j] * 10 + a1[i];
        cnt[x]++;
        cnt[y]++;
      }
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        int x = a3[i] * 10 + a2[j];
        int y = a2[j] * 10 + a3[i];
        cnt[x]++;
        cnt[y]++;
      }
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 6; k++) {
          int x = a1[i] * 100 + a2[j] * 10 + a3[k];
          int y = a1[i] * 100 + a3[k] * 10 + a2[j];
          int z = a2[j] * 100 + a3[k] * 10 + a1[i];
          int a = a2[j] * 100 + a1[i] * 10 + a3[k];
          int b = a3[k] * 100 + a1[i] * 10 + a2[j];
          int c = a3[k] * 100 + a2[j] * 10 + a1[i];
          cnt[x]++;
          cnt[y]++;
          cnt[z]++;
          cnt[a]++;
          cnt[b]++;
          cnt[c]++;
        }
      }
    }
    for (int i = 1;; i++) {
      if (cnt[i] == 0) {
        cout << i - 1;
        return 0;
      }
    }
  }
  return 0;
}
