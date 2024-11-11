#include <bits/stdc++.h>
using namespace std;
const int Max = 3e5 + 10;
const int Mod = 1e9 + 7;
const int N = 1e6;
int D[N + 10];
void Cin(int &num) {
  num = 0;
  char ch = getchar();
  int flag = 0;
  while (!((ch >= '0' & ch <= '9') || ch == '-')) {
    ch = getchar();
  }
  if (ch == '-') {
    flag = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    num = (num << 1) + (num << 3) + ch - '0';
    ch = getchar();
  }
  if (flag == 1) {
    num = 0 - num;
  }
}
void Cout(long long n) {
  long long num = n, rev = n, cnt = 0;
  char ch;
  if (n == 0) {
    putchar('0');
    return;
  }
  while (rev % 10 == 0) {
    cnt++;
    rev /= 10;
  }
  rev = 0;
  while (num > 0) {
    rev = (rev << 3) + (rev << 1) + num % 10;
    num /= 10;
  }
  while (rev > 0) {
    ch = (rev % 10) + '0';
    putchar(ch);
    rev /= 10;
  }
  while (cnt--) putchar('0');
  putchar('\n');
}
void divisor() {
  int i, j;
  for (i = 1; i <= N; i++) {
    for (j = i; j <= N; j += i) D[j]++;
  }
}
long long tree[Max + 10];
int mp[Max + 10];
long long query(int idx) {
  long long sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= idx & (-idx);
  }
  return sum;
}
void update(int idx, int x, int n) {
  while (idx <= n) {
    tree[idx] += x;
    idx += idx & (-idx);
  }
}
void input(int ara[], int n) {
  ara[0] = 0;
  mp[0] = 0;
  for (int i = 1; i <= n; i++) {
    Cin(ara[i]);
    update(i, ara[i], n);
    if (ara[i] <= 2)
      mp[i] = i + 1;
    else
      mp[i] = i;
  }
  mp[n] = n;
  mp[n + 1] = n + 1;
}
int next(int n) {
  if (mp[n] == n)
    return n;
  else
    return mp[n] = next(mp[n]);
}
int main() {
  int i, n, t, l, r, q;
  divisor();
  Cin(n);
  Cin(q);
  int ara[n + 2];
  input(ara, n);
  while (q--) {
    Cin(t);
    Cin(l);
    Cin(r);
    if (t == 1) {
      while ((l = next(l)) <= r) {
        update(l, -ara[l] + D[ara[l]], n);
        ara[l] = D[ara[l]];
        if (ara[l] <= 2) {
          mp[l] = next(l + 1);
        }
        l++;
      }
    } else {
      printf("%lld\n", query(r) - query(l - 1));
    }
  }
}
