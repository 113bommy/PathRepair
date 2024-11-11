#include <bits/stdc++.h>
using namespace std;
bool board[1005][1005];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    board[a][b] = 1;
  }
  long long fans = 0;
  for (long long i = 1; i <= 1000; i++) {
    long long temp = i;
    long long ans = 0;
    for (long long j = 1; temp <= 1000 && j <= 1000;) {
      if (board[temp][j]) ans++;
      j++;
      temp++;
    }
    fans += (long long)(ans) * (ans - 1) / 2;
  }
  for (long long j = 2; j <= 1000; j++) {
    long long temp = j;
    long long ans = 0;
    for (long long i = 1; temp <= 1000 && j <= 1000;) {
      if (board[i][temp]) ans++;
      i++;
      temp++;
    }
    fans += (long long)(ans) * (ans - 1) / 2;
  }
  for (long long i = 1; i <= 1000; i++) {
    long long temp = i;
    long long ans = 0;
    for (long long j = 1000; j > 0 && temp <= 1000;) {
      if (board[temp][j]) ans++;
      temp++;
      j--;
    }
    fans += (long long)(ans) * (ans - 1) / 2;
  }
  for (long long j = 1; j <= 999; j++) {
    long long temp = j;
    long long ans = 0;
    for (long long i = 1; i <= 1000 && temp > 0;) {
      if (board[i][temp]) ans++;
      temp--;
      i++;
    }
    fans += (long long)(ans) * (ans - 1) / 2;
  }
  cout << fans;
  return 0;
}
