#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N];
vector<int> v;
int s[4 * N], ans[N];
void RAWUPD(int &a, int first) {
  if (first < 0)
    a = first;
  else {
    if (a >= 0)
      a += first, a %= 2;
    else if (first % 2 == 1)
      a = -3 - a;
  }
}
void PUSH(int S, int l, int r) {
  int first = s[S];
  s[S] = 0;
  if (l != r) {
    RAWUPD(s[S * 2], first);
    RAWUPD(s[S * 2 + 1], first);
  } else
    RAWUPD(ans[l], first);
}
void LOWUD(int S, int l, int r, int first, char c) {
  if (c == '>' && first <= 0) s[S]++;
  if (c == '<' && first >= 0) s[S]++;
}
void MIDUD(int S, int l, int r, int first, char c) {
  if (c == '<' && first >= 0) s[S] = -2;
  if (c == '>' && first <= 0) s[S] = -1;
}
void HIGUD(int S, int l, int r, int first, char c) {
  if (c == '<') s[S] = -2;
  if (c == '>') s[S] = -1;
}
void UPD(int S, int l, int r, int first, char c) {
  PUSH(S, l, r);
  if (r < abs(first))
    LOWUD(S, l, r, first, c);
  else if (l == r && abs(first) == r)
    MIDUD(S, l, r, first, c);
  else if (abs(first) < l)
    HIGUD(S, l, r, first, c);
  else {
    UPD(S * 2, l, (l + (r - l) / 2), first, c);
    UPD(S * 2 + 1, (l + (r - l) / 2) + 1, r, first, c);
    return;
  }
  PUSH(S, l, r);
}
void ANS(int S, int l, int r) {
  PUSH(S, l, r);
  if (l == r) return;
  ANS(S * 2, l, (l + (r - l) / 2));
  ANS(S * 2 + 1, (l + (r - l) / 2) + 1, r);
}
int main() {
  n = ({
    long long first = 0;
    int n = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) n = c == '-';
    for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
    n ? -first : first;
  }),
  q = ({
    long long first = 0;
    int n = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) n = c == '-';
    for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
    n ? -first : first;
  });
  for (int i = 1; i <= n; i++)
    a[i] = ({
      long long first = 0;
      int n = 0, c = getchar();
      for (; !isdigit(c); c = getchar()) n = c == '-';
      for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
      n ? -first : first;
    });
  for (int ___ = 1; ___ <= q; ___++)
    UPD(1, 1, 1e5, ({
          long long first = 0;
          int n = 0, c = getchar();
          for (; !isdigit(c); c = getchar()) n = c == '-';
          for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
          n ? -first : first;
        }),
        ({
          char c = getchar();
          while (c == ' ' || c == '\n') c = getchar();
          c;
        }));
  ANS(1, 1, 1e5);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      cout << 0 << " ";
      continue;
    }
    int first = abs(a[i]);
    int second = ans[first];
    if (second == -1) cout << -first;
    if (second == -2) cout << first;
    if (second == 0) cout << a[i];
    if (second == 1) cout << -a[i];
    cout << " ";
  }
}
