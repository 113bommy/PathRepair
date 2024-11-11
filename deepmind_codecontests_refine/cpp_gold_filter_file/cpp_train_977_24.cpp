#include <bits/stdc++.h>
using namespace std;
const int Infinity = 1000000001;
long int Max, kq;
int n, A[200000], f[200000];
void Sort(int Left, int Right) {
  int i = Left;
  int j = Right;
  int Mid = f[(Left + Right) / 2];
  while (i <= j) {
    while (f[i] < Mid) i++;
    while (f[j] > Mid) j--;
    if (i <= j) {
      int tmp = f[i];
      f[i] = f[j];
      f[j] = tmp;
      i++;
      j--;
    }
  }
  if (Left < j) Sort(Left, j);
  if (i < Right) Sort(i, Right);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) f[i] = Infinity;
  f[0] = -Infinity;
  for (int i = 1; i <= n; i++) {
    int Mid;
    int Left = 1;
    int Right = n;
    while (Right > Left + 1) {
      Mid = (Left + Right) / 2;
      if (f[Mid - 1] >= A[i])
        Right = Mid;
      else
        Left = Mid;
    }
    if (f[Right - 1] <= A[i])
      if (f[Right] > A[i]) Max = Right;
    if (f[Left - 1] <= A[i])
      if (f[Left] > A[i]) Max = Left;
    f[Max] = A[i];
    if (Max > kq) kq = Max;
  }
  cout << kq;
  return 0;
}
