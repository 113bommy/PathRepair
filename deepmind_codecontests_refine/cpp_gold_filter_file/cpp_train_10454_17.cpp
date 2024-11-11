#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x;
  long long y;
};
long long gcd(long long a, long long b) {
  return b == 0 ? a : a > b ? gcd(b, a % b) : gcd(a, b % a);
}
bool myfunc(struct node a, struct node b) {
  if (a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}
long long fibo[10010];
string s1, s2;
long long two[5010];
long long three[5010];
int main() {
  long long k, x, n, m;
  int m1;
  int j;
  cin >> k >> x >> n >> m;
  int i;
  int l;
  if (x == 0) {
    for (i = 1; i <= n; i++) {
      cout << "A";
    }
    cout << endl;
    for (i = 1; i <= m; i++) {
      cout << "B";
    }
    cout << endl;
    return 0;
  }
  s1 = "";
  s2 = "";
  two[1] = 0;
  two[2] = 0;
  fibo[1] = 0;
  fibo[2] = 1;
  int prev_fst;
  int prev_lst;
  int prev_prev_fst;
  int prev_prev_lst;
  prev_lst = 1;
  prev_prev_fst = 2;
  prev_fst = 3;
  prev_prev_lst = 4;
  for (i = 3; i <= 50; i++) {
    two[i] = two[i - 2] + two[i - 1];
    if (prev_prev_lst == 1 && prev_fst == 2) {
      two[i]++;
      int current_lst = prev_lst;
      int current_fst = prev_prev_fst;
      prev_prev_fst = prev_fst;
      prev_prev_lst = prev_lst;
      prev_lst = current_lst;
      prev_fst = current_fst;
    } else {
      int current_lst = prev_lst;
      int current_fst = prev_prev_fst;
      prev_prev_fst = prev_fst;
      prev_prev_lst = prev_lst;
      prev_lst = current_lst;
      prev_fst = current_fst;
    }
  }
  three[1] = 0;
  three[2] = 0;
  prev_lst = 1;
  prev_fst = 2;
  prev_prev_fst = 3;
  prev_prev_lst = 4;
  for (i = 3; i <= 50; i++) {
    three[i] = three[i - 1] + three[i - 2];
    if (prev_prev_lst == 1 && prev_fst == 2) {
      three[i]++;
      int current_lst = prev_lst;
      int current_fst = prev_prev_fst;
      prev_prev_fst = prev_fst;
      prev_prev_lst = prev_lst;
      prev_lst = current_lst;
      prev_fst = current_fst;
    } else {
      int current_lst = prev_lst;
      int current_fst = prev_prev_fst;
      prev_prev_fst = prev_fst;
      prev_prev_lst = prev_lst;
      prev_lst = current_lst;
      prev_fst = current_fst;
    }
  }
  long long occ = 0;
  for (i = 3; i <= 50; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  string temps1, temps2;
  for (i = 0; i <= 15; i++) {
    temps1 = "";
    temps2 = "";
    int b1, b2, b3, b4;
    b1 = (i & 8) ? 1 : 0;
    b2 = (i & 4) ? 1 : 0;
    b3 = (i & 2) ? 1 : 0;
    b4 = (i & 1) ? 1 : 0;
    long long ans = 0;
    int tempn, tempm;
    tempn = n;
    tempm = m;
    if (b1 == 1) {
      tempn--;
    }
    if (b2 == 1) {
      tempn--;
    }
    if (b3 == 1) {
      tempm--;
    }
    if (b4 == 1) {
      tempm--;
    }
    if (b2 == 1 && b3 == 1) {
      ans += fibo[k - 1];
    }
    if (b1 == 1 && b4 == 1) {
      ans += two[k];
    }
    if (b3 == 1 && b4 == 1) {
      ans += three[k];
    }
    int flg = 0;
    for (j = 0; j <= tempn / 2 && tempn >= 0 && tempm >= 0; j++) {
      for (l = 0; l <= tempm / 2; l++) {
        if (fibo[k - 1] * j + fibo[k] * l + ans == x) {
          int which_char = 0;
          if (b1 == 1) {
            temps1 += 'C';
            which_char = 1;
          }
          for (m1 = 1; m1 <= j; m1++) {
            temps1 += "AC";
            which_char += 2;
          }
          for (m1 = which_char; m1 < n - 1; m1++) {
            temps1 += 'F';
          }
          if (b2 == 1 && m1 < n) {
            temps1 += 'A';
          } else if (m1 < n) {
            temps1 += 'F';
          }
          which_char = 0;
          if (b3 == 1) {
            temps2 += 'C';
            which_char = 1;
          }
          for (m1 = 1; m1 <= l; m1++) {
            temps2 += "AC";
            which_char += 2;
          }
          for (m1 = which_char; m1 < m - 1; m1++) {
            temps2 += 'F';
          }
          if (b4 == 1 && m1 < m) {
            temps2 += 'A';
          } else if (m1 < m) {
            temps2 += 'F';
          }
          cout << temps1 << endl << temps2 << endl;
          return 0;
        }
      }
    }
  }
  cout << "Happy new year!\n";
  return 0;
}
