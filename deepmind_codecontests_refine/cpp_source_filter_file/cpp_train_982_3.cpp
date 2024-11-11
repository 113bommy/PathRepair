#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, d;
  long long int k;
  cin >> n >> k >> d;
  int **A;
  A = (int **)malloc(d * sizeof(int *));
  int i, j;
  for (i = 0; i < d; ++i) {
    A[i] = (int *)malloc(n * sizeof(int));
  }
  int flag = 1;
  long long int pw = 1;
  for (i = 0; i < d; ++i) {
    pw *= k;
    if (pw > n) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << "-1";
    return 0;
  }
  long long int jump, count;
  jump = 1;
  int num;
  for (i = 0; i < d; ++i) {
    count = jump;
    num = 0;
    for (j = 0; j < n; ++j) {
      A[i][j] = num;
      count--;
      if (count == 0) {
        count = jump;
        num++;
        if (num == k) num = 0;
      }
    }
    jump *= k;
  }
  for (i = 0; i < d; ++i) {
    for (j = 0; j < n; ++j) {
      cout << A[i][j] + 1;
    }
    cout << endl;
  }
  return 0;
}
