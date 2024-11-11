#include <bits/stdc++.h>
using namespace std;
void findAllDevisers(int n, queue<int> &q) {
  for (int i = 1; i <= n / 3; i++) {
    if (n % i == 0) q.push(i);
  }
}
int findResult(int *arr, int n) {
  queue<int> devisers;
  findAllDevisers(n, devisers);
  int maxSum = -20000000;
  int curSum;
  while (devisers.size() != 0) {
    int curDev = devisers.front();
    devisers.pop();
    for (int i = 0; i < curDev; i++) {
      curSum = 0;
      for (int j = i; j < n; j += curDev) {
        curSum += arr[j];
      }
      if (curSum > maxSum) maxSum = curSum;
    }
  }
  return maxSum;
}
int main() {
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  cout << findResult(arr, n);
  delete arr;
  return 0;
}
