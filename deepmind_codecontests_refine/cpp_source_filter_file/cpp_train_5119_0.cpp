#include <bits/stdc++.h>
using namespace std;
class binaryindexed {
 public:
  int N;
  int *arr;
  binaryindexed(int N, int *marr) {
    this->N = N;
    arr = new int[N + 1];
    for (int i = 0; i <= N; i++) {
      arr[i] = 0;
    }
    for (int i = 0; i < N; i++) {
      update(i, marr[i]);
    }
  }
  int getRangeSum(int i, int l) {
    int sum = 0;
    int x = l + 1;
    while (x != 0) {
      sum += arr[x];
      x = x - (x & (-x));
    }
    return sum;
  }
  void update(int x, int val) {
    x = x + 1;
    while (x <= N) {
      arr[x] += val;
      x += (x & (-x));
    }
  }
};
int main() {
  string s1, s2;
  int n, m;
  cin >> n >> m;
  int arr[n];
  int i = 0;
  int len = n;
  while (n--) {
    cin >> arr[i++];
  }
  vector<int> vec;
  vec.push_back(arr[0]);
  cout << "0 ";
  long long int total = arr[0];
  for (i = 1; i < len; i++) {
    int ctr = 0;
    if (m - (total + arr[i]) < 0) {
      long long int fake = total + arr[i];
      int j = vec.size() - 1;
      while (m - fake < 0) {
        fake -= vec[j--];
        ctr++;
      }
    }
    if (i != len - 1) {
      cout << ctr << " ";
    } else {
      cout << ctr;
    }
    int j = i - 1;
    int cur = i;
    vec.push_back(arr[i]);
    total += arr[i];
    while (cur >= 0 && vec[cur] < vec[j]) {
      swap(vec[cur], vec[j]);
      cur--;
      j--;
    }
  }
  return 0;
}
