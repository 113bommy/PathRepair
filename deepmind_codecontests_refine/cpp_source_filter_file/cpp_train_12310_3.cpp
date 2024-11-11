#include <bits/stdc++.h>
using namespace std;
int findmax(int* p, int k) {
  int max = *p;
  int pos = 0;
  for (int i = 1; i < k; i++) {
    int n = *(p + i);
    if (n > max) {
      max = n;
      pos = i;
    }
  }
  *(p + pos) = 0;
  return max;
}
int findmin(int* p, int k) {
  int min = *p;
  int pos = 0;
  for (int i = 1; i < k; i++) {
    int n = *(p + i);
    if (n < min) {
      min = n;
      pos = i;
    }
  }
  *(p + pos) = 31;
  return min;
}
int findsum(int* p, int k) {
  int sum = 0;
  for (int i = 0; i < k; i++) {
    int n = *(p + i);
    sum = sum + n;
  }
  return sum;
}
int main() {
  int testcases;
  cin >> testcases;
  int* a = new int[30];
  int* b = new int[30];
  for (int i = 0; i < testcases; i++) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
      cin >> *(a + i);
    }
    for (int i = 0; i < n; i++) {
      cin >> *(b + i);
    }
    int summ = findsum(a, k);
    for (int i = 0; i < k; i++) {
      int mina = findmin(a, k);
      int maxb = findmax(b, k);
      if (mina < maxb) {
        summ = summ + maxb - mina;
      } else {
        break;
      }
    }
    cout << summ << endl;
  }
  return 0;
}
