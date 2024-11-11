#include <bits/stdc++.h>
using namespace std;
int N, K;
int arr[2000][2] = {0};
int profit[2000][2] = {0};
int minInfo[2] = {0};
void getMin() {
  int temp;
  int idx;
  for (int i = 0; i < K; i++) {
    if (i == 0) {
      temp = profit[i][0];
      idx = i;
    } else {
      if (temp > profit[i][0]) {
        temp = profit[i][0];
        idx = i;
      }
    }
  }
  minInfo[0] = temp;
  minInfo[1] = idx;
}
int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> arr[i][0];
  }
  for (int i = 0; i < N; i++) {
    if (i < K) {
      profit[i][0] = arr[i][0];
      profit[i][1] = i;
      if (i == K - 1) {
        getMin();
      }
    } else {
      if (minInfo[0] < arr[i][0]) {
        profit[minInfo[1]][0] = arr[i][0];
        profit[minInfo[1]][1] = i;
        getMin();
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < K; i++) {
    sum += profit[i][0];
    arr[profit[i][1]][1] = 1;
  }
  cout << sum << endl;
  int prev = -1;
  int flag = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i][1] == 1) {
      if (flag == 0) {
        flag = 1;
      } else {
        if (prev == -1) {
          cout << i << " ";
          prev = i;
        } else {
          cout << i - prev << " ";
          prev = i;
        }
      }
    }
  }
  cout << N - prev;
  return 0;
}
