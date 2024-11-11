#include <bits/stdc++.h>
using namespace std;
long long solve(int n, vector<int> arr1) {
  vector<int> arr(n);
  long long answer = 0;
  for (int i = 0; i < n; ++i) {
    arr[i] = arr1[i];
    if (i != 0 and arr[i - 1] > arr[i]) {
      arr[i] = arr[i - 1];
    }
  }
  for (int i = n - 1; i > 0; --i) {
    if (arr[i] > arr[i - 1] + 1) {
      arr[i - 1] = arr[i] - 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    answer += arr[i] - arr1[i];
  }
  return answer;
}
int solve_stupid(int n, vector<int> arr) {
  int answer = 0;
  for (int i = 1; i < n; ++i) {
    if (arr[i] < arr[i - 1]) {
      answer += arr[i - 1] - arr[i];
      arr[i] = arr[i - 1];
    }
    int j = i - 1;
    while (arr[j + 1] > arr[j] + 1) {
      answer += arr[j + 1] - 1 - arr[j];
      arr[j] = arr[j + 1] - 1;
      --j;
    }
  }
  return answer;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cout << solve(n, v) << endl;
}
