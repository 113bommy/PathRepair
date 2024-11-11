#include <bits/stdc++.h>
using namespace std;
const long long MAX = 3e5 + 9;
const long long INF = 1e12;
string X[MAX];
char arr[] = {'A', 'G', 'C', 'T'};
int N, M, res, cnt[2][300009][30], cnt2[2][300009][30];
int check1(int f, int s, int ff, int ss) {
  int res = 0;
  for (int A = 0; A < M; A++) {
    if (A % 2 == 0)
      res += max(cnt[0][A][f - 'A'] + cnt[1][A][s - 'A'],
                 cnt[0][A][s - 'A'] + cnt[1][A][f - 'A']);
    else
      res += max(cnt[0][A][ff - 'A'] + cnt[1][A][ss - 'A'],
                 cnt[0][A][ss - 'A'] + cnt[1][A][ff - 'A']);
  }
  return N * M - res;
}
int check2(int f, int s, int ff, int ss) {
  int res = 0;
  for (int A = 0; A < N; A++) {
    if (A % 2 == 0)
      res += max(cnt2[0][A][f - 'A'] + cnt2[1][A][s - 'A'],
                 cnt2[0][A][s - 'A'] + cnt2[1][A][f - 'A']);
    else
      res += max(cnt2[0][A][ff - 'A'] + cnt2[1][A][ss - 'A'],
                 cnt2[0][A][ss - 'A'] + cnt2[1][A][ff - 'A']);
  }
  return N * M - res;
}
void print1(int f, int s, int ff, int ss) {
  vector<char> res1, res2;
  for (int A = 0; A < M; A++) {
    if (A % 2 == 0) {
      if (cnt[0][A][f - 'A'] + cnt[1][A][s - 'A'] >
          cnt[0][A][s - 'A'] + cnt[1][A][f - 'A'])
        res1.push_back(f), res2.push_back(s);
      else
        res1.push_back(s), res2.push_back(f);
    } else {
      if (cnt[0][A][ff - 'A'] + cnt[1][A][ss - 'A'] >
          cnt[0][A][ss - 'A'] + cnt[1][A][ff - 'A'])
        res1.push_back(ff), res2.push_back(ss);
      else
        res1.push_back(ss), res2.push_back(ff);
    }
  }
  for (int A = 0; A < N; A++) {
    if (A % 2 == 0)
      for (auto A : res1) cout << A;
    else
      for (auto A : res2) cout << A;
    cout << "\n";
  }
  exit(0);
  return;
}
void print2(int f, int s, int ff, int ss) {
  for (int A = 0; A < N; A++) {
    if (A % 2 == 0) {
      if (cnt2[0][A][f - 'A'] + cnt2[1][A][s - 'A'] <
          cnt2[0][A][s - 'A'] + cnt2[1][A][f - 'A'])
        swap(f, s);
      for (int B = 0; B < M; B++) cout << (B % 2 == 0 ? (char)f : (char)s);
    } else {
      if (cnt2[0][A][ff - 'A'] + cnt2[1][A][ss - 'A'] <
          cnt2[0][A][ss - 'A'] + cnt2[1][A][ff - 'A'])
        swap(ff, ss);
      for (int B = 0; B < M; B++) cout << (B % 2 == 0 ? (char)ff : (char)ss);
    }
    cout << "\n";
  }
  exit(0);
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  res = MAX;
  cin >> N >> M;
  for (int A = 0; A < N; A++) {
    cin >> X[A];
    for (int B = 0; B < M; B++)
      cnt[A % 2][B][X[A][B] - 'A']++, cnt2[B % 2][A][X[A][B] - 'A']++;
  }
  for (int A = 0; A < 4; A++) {
    for (int B = 0; B < 4; B++) {
      if (B == A) continue;
      for (int C = 0; C < 4; C++) {
        if (C == B or C == A) continue;
        for (int D = 0; D < 4; D++) {
          if (D == C or D == B or D == A) continue;
          res = min(res, check1(arr[A], arr[B], arr[C], arr[D]));
          res = min(res, check2(arr[A], arr[B], arr[C], arr[D]));
        }
      }
    }
  }
  for (int A = 0; A < 4; A++) {
    for (int B = 0; B < 4; B++) {
      if (B == A) continue;
      for (int C = 0; C < 4; C++) {
        if (C == B or C == A) continue;
        for (int D = 0; D < 4; D++) {
          if (D == C or D == B or D == A) continue;
          if (check1(arr[A], arr[B], arr[C], arr[D]) == res)
            print1(arr[A], arr[B], arr[C], arr[D]);
          if (check2(arr[A], arr[B], arr[C], arr[D]) == res)
            print2(arr[A], arr[B], arr[C], arr[D]);
        }
      }
    }
  }
  return 0;
}
