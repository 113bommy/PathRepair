#include <bits/stdc++.h>
using namespace std;
long sumcom[120];
int loc;
bool used[5];
int times;
int arr[5][5];
void findsum(int len, int cur) {
  times++;
  int i;
  for (i = 0; i < 5; i++) {
    if (used[i]) continue;
    used[i] = true;
    if (cur != -1) {
      if (times == 2 || times == 3)
        sumcom[loc] += arr[cur][i] + arr[i][cur];
      else
        sumcom[loc] += (arr[cur][i] + arr[i][cur]) * 2;
    }
    if (len == 1) {
      loc++;
      if (loc < 119) sumcom[loc] = sumcom[loc - 1];
    }
    if (len > 1) findsum(len - 1, i);
    if (cur != -1 && loc < 119) {
      if (times == 2 || times == 3)
        sumcom[loc] -= arr[cur][i] + arr[i][cur];
      else
        sumcom[loc] -= (arr[cur][i] + arr[i][cur]) * 2;
    }
    used[i] = false;
  }
  times--;
}
int main() {
  loc = 0;
  times = 0;
  int i, j;
  long sum = 0;
  for (i = 0; i < 120; i++) {
    sumcom[i] = 0;
  }
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }
  findsum(5, -1);
  long max = sumcom[0];
  for (i = 1; i < 120; i++) {
    if (sumcom[i] > max) max = sumcom[i];
  }
  cout << max;
  return 0;
}
