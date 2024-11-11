#include <bits/stdc++.h>
using namespace std;
int n, k;
int num[10][10], a[10], visit[10];
long long numb[10], diff;
void fun() {
  for (int i = 1; i <= n; i++) {
    long long x = 0;
    for (int j = 1; j <= k; j++) {
      x = x * 10 + num[i][a[j]];
    }
    numb[i] = x;
  }
  long long max = 0, min = 999999999;
  for (int i = 1; i <= n; i++) {
    if (min > numb[i]) min = numb[i];
    if (max < numb[i]) max = numb[i];
  }
  if (diff > max - min) diff = max - min;
}
void permute(int indx) {
  if (indx == k + 1) {
    fun();
    return;
  }
  for (int i = 1; i <= k; i++) {
    if (visit[i] == 1) continue;
    visit[i] = 1;
    a[indx] = i;
    permute(indx + 1);
    visit[i] = 0;
  }
}
int main() {
  long long x;
  cin >> n >> k;
  diff = 999999999;
  for (int i = 1; i <= n; i++) {
    int j = k;
    cin >> x;
    while (x > 0) {
      num[i][j] = x % 10;
      x = x / 10;
      j--;
    }
  }
  permute(1);
  cout << diff;
}
