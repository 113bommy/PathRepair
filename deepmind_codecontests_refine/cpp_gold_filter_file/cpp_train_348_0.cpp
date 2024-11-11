#include <bits/stdc++.h>
using namespace std;
int cnt1, cnt2, cnt, n, m, k, A, B, C, D, i, j, l, v[100005], sum1, sum2, Q, Q2,
    nowx, nowy, ans, P, L, R, mid, CNT;
struct node {
  int x, y, z;
} t1[100005], t2[100005], h[100005], s[100005], S[100005], H[100005];
int cmp(node i, node j) { return i.x < j.x; }
int OK(int x) {
  int sum = 0;
  for (int i = 1; i <= CNT; i++)
    if (H[i].x <= x) {
      if (H[i].y <= x)
        sum += H[i].y - H[i].x + 1;
      else
        sum += x - H[i].x + 1;
    }
  return x - sum;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= k; i++) {
    scanf("%d%d%d%d", &A, &B, &C, &D);
    if (A == C) {
      t1[++cnt1].x = A;
      t1[cnt1].y = min(B, D);
      t1[cnt1].z = max(B, D);
    } else {
      t2[++cnt2].x = B;
      t2[cnt2].y = min(A, C);
      t2[cnt2].z = max(A, C);
    }
  }
  sort(t1 + 1, t1 + cnt1 + 1, cmp);
  sort(t2 + 1, t2 + cnt2 + 1, cmp);
  for (j = 1, i = 2; i <= cnt1 + 1; i++)
    if (i == cnt1 + 1 || t1[i].x != t1[i - 1].x) {
      cnt = 0;
      sum1++;
      for (k = j; k < i; k++) {
        h[++cnt].x = t1[k].y;
        h[cnt].y = t1[k].z;
      }
      sort(h + 1, h + cnt + 1, cmp);
      s[++Q].x = m;
      s[Q].y = t1[i - 1].x;
      nowx = nowy = 0;
      for (k = 1; k <= cnt; k++)
        if (h[k].x <= nowy)
          nowy = max(nowy, h[k].y);
        else {
          s[Q].x -= (nowy - nowx);
          nowx = h[k].x;
          nowy = h[k].y;
        }
      s[Q].x -= (nowy - nowx);
      j = i;
    }
  for (j = 1, i = 2; i <= cnt2 + 1; i++)
    if (i == cnt2 + 1 || t2[i].x != t2[i - 1].x) {
      cnt = 0;
      sum2++;
      for (k = j; k < i; k++) {
        h[++cnt].x = t2[k].y;
        h[cnt].y = t2[k].z;
      }
      sort(h + 1, h + cnt + 1, cmp);
      S[++Q2].x = n;
      S[Q2].y = t2[i - 1].x;
      nowx = nowy = 0;
      for (k = 1; k <= cnt; k++)
        if (h[k].x <= nowy)
          nowy = max(nowy, h[k].y);
        else {
          S[Q2].x -= (nowy - nowx);
          nowx = h[k].x;
          nowy = h[k].y;
        }
      S[Q2].x -= (nowy - nowx);
      j = i;
    }
  if ((n - sum1) % 2 == 0) {
    s[++Q].x = m;
    t1[cnt1 + 1].x = n;
    for (i = 1; i <= cnt1 + 1; i++)
      if (t1[i].x - t1[i - 1].x >= 2) {
        s[Q].y = t1[i].x - 1;
        break;
      }
  }
  if ((m - sum2) % 2 == 0) {
    S[++Q2].x = n;
    t2[cnt2 + 1].x = m;
    for (i = 1; i <= cnt2 + 1; i++)
      if (t2[i].x - t2[i - 1].x >= 2) {
        S[Q2].y = t2[i].x - 1;
        break;
      }
  }
  for (i = 1; i <= Q; i++) ans ^= s[i].x;
  for (i = 1; i <= Q2; i++) ans ^= S[i].x;
  if (!ans) {
    cout << "SECOND";
    return 0;
  }
  cout << "FIRST" << endl;
  for (i = 1; i <= Q; i++)
    if ((s[i].x ^ ans) < s[i].x) break;
  if (i <= Q) {
    cout << s[i].y << ' ' << 0 << ' ' << s[i].y << ' ';
    j = i;
    cnt = 0;
    for (i = 1; i <= cnt1; i++)
      if (t1[i].x == s[j].y) {
        h[++cnt].x = t1[i].y;
        h[cnt].y = t1[i].z;
      }
    sort(h + 1, h + cnt + 1, cmp);
    nowx = nowy = 0;
    for (k = 1; k <= cnt; k++)
      if (h[k].x <= nowy)
        nowy = max(nowy, h[k].y);
      else {
        H[++CNT].x = nowx + 1;
        H[CNT].y = nowy;
        nowx = h[k].x;
        nowy = h[k].y;
      }
    H[++CNT].x = nowx + 1;
    H[CNT].y = nowy;
    L = 1;
    R = m;
    mid = (L + R) / 2;
    s[j].x = s[j].x - (s[j].x ^ ans);
    while (L <= R) {
      if (OK(mid) >= s[j].x) {
        R = mid - 1;
        mid = (L + R) / 2;
      } else {
        L = mid + 1;
        mid = (L + R) / 2;
      }
    }
    cout << L << endl;
    return 0;
  }
  for (i = 1; i <= Q2; i++)
    if ((S[i].x ^ ans) < S[i].x) break;
  cout << 0 << ' ' << S[i].y << ' ';
  P = S[i].y;
  j = i;
  cnt = 0;
  for (i = 1; i <= cnt2; i++)
    if (t2[i].x == S[j].y) {
      h[++cnt].x = t2[i].y;
      h[cnt].y = t2[i].z;
    }
  sort(h + 1, h + cnt + 1, cmp);
  nowx = nowy = 0;
  for (k = 1; k <= cnt; k++)
    if (h[k].x <= nowy)
      nowy = max(nowy, h[k].y);
    else {
      H[++CNT].x = nowx + 1;
      H[CNT].y = nowy;
      nowx = h[k].x;
      nowy = h[k].y;
    }
  H[++CNT].x = nowx + 1;
  H[CNT].y = nowy;
  S[j].x = S[j].x - (S[j].x ^ ans);
  L = 1;
  R = n;
  mid = (L + R) / 2;
  while (L <= R) {
    if (OK(mid) >= S[j].x) {
      R = mid - 1;
      mid = (L + R) / 2;
    } else {
      L = mid + 1;
      mid = (L + R) / 2;
    }
  }
  cout << L << ' ' << P << endl;
  return 0;
}
