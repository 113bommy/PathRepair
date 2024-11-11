#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long modpow[10];
  long long modpow1[20];
  modpow[0] = 1;
  modpow1[0] = 1;
  for (int i = 1; i < 10; i++) {
    modpow[i] = modpow[i - 1] * 4;
  }
  for (int i = 1; i < 20; i++) {
    modpow1[i] = modpow1[i - 1] * 2;
  }
  while (t--) {
    long long n;
    cin >> n;
    long long q = 0;
    ;
    int jj = 0;
    while (4 * (q + 1) - 1 < n) {
      q = 4 * (q + 1) - 1;
      jj++;
    }
    n = n - q;
    vector<int> ans1;
    long long a = (n - 1) / 3;
    long long answer = 0;
    if (n % 3 == 1) {
      ans1.push_back(0);
      ans1.push_back(1);
      int u = 0;
      n = a;
      u = jj;
      int q = 0;
      vector<int> ans2;
      while (n >= 0 && q < u) {
        ans2.push_back(n % 4);
        n = n / 4;
        q++;
      }
      int r = ans2.size() - 1;
      while (r >= 0) {
        if (ans2[r] == 0) {
          ans1.push_back(0);
          ans1.push_back(0);
        } else if (ans2[r] == 1) {
          ans1.push_back(0);
          ans1.push_back(1);
        } else if (ans2[r] == 2) {
          ans1.push_back(1);
          ans1.push_back(0);
        } else {
          ans1.push_back(1);
          ans1.push_back(1);
        }
        r--;
      }
      int h = ans1.size() - 1;
      long long g = modpow1[h];
      for (int a = 0; a < ans1.size(); a++) {
        answer += g * ans1[a];
        g = g / 2;
      }
    } else if (n % 3 == 2) {
      n = a;
      ans1.push_back(1);
      ans1.push_back(0);
      int u = 0;
      u = jj;
      int q = 0;
      vector<int> ans2;
      while (n >= 0 && q < u) {
        ans2.push_back(n % 4);
        n = n / 4;
        q++;
      }
      int r = ans2.size() - 1;
      while (r >= 0) {
        if (ans2[r] == 0) {
          ans1.push_back(0);
          ans1.push_back(0);
        } else if (ans2[r] == 1) {
          ans1.push_back(1);
          ans1.push_back(0);
        } else if (ans2[r] == 2) {
          ans1.push_back(1);
          ans1.push_back(1);
        } else {
          ans1.push_back(0);
          ans1.push_back(1);
        }
        r--;
      }
      int h = ans1.size() - 1;
      long long g = modpow1[h];
      for (int a = 0; a < ans1.size(); a++) {
        answer += g * ans1[a];
        g = g / 2;
      }
    } else {
      n = a;
      ans1.push_back(1);
      ans1.push_back(1);
      int u = jj;
      int q = 0;
      vector<int> ans2;
      while (n >= 0 && q < u) {
        ans2.push_back(n % 4);
        n = n / 4;
        q++;
      }
      int r = ans2.size() - 1;
      while (r >= 0) {
        if (ans2[r] == 0) {
          ans1.push_back(0);
          ans1.push_back(0);
        } else if (ans2[r] == 1) {
          ans1.push_back(1);
          ans1.push_back(1);
        } else if (ans2[r] == 2) {
          ans1.push_back(0);
          ans1.push_back(1);
        } else {
          ans1.push_back(1);
          ans1.push_back(0);
        }
        r--;
      }
      int h = ans1.size() - 1;
      long long g = modpow1[h];
      for (int a = 0; a < ans1.size(); a++) {
        answer += g * ans1[a];
        g = g / 2;
      }
    }
    printf("%lld \n", answer);
  }
  return 0;
}
