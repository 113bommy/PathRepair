#include <bits/stdc++.h>
using namespace std;
int N;
int A[100010] = {0};
int id[100010] = {0};
int Rank[100010] = {0};
bool cmp(int a1, int a2) {
  return A[a1] < A[a2] || (A[a1] == A[a2] && a1 < a2);
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    id[i] = i;
  }
  sort(id + 1, id + N + 1, cmp);
  for (int i = 1; i <= N; i++) Rank[id[i]] = i;
  int Min = 1, Max = Rank[1], Cnt = 1;
  int Ans = 0;
  for (int i = 2; i <= N; i++) {
    if (Max - Min + 1 == Cnt) {
      Min = Max + 1, Max = Rank[i];
      Cnt = 1;
      Ans++;
    } else {
      if (Rank[i] > Max) Max = Rank[i];
      Cnt++;
    }
  }
  Ans++;
  cout << Ans << endl;
  return 0;
}
