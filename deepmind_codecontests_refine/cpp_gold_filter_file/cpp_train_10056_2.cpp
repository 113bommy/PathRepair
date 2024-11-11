#include <bits/stdc++.h>
using namespace std;
long long int trash = 0;
long long int a[50], c[50];
long long int value2power[50];
long long int n, m;
priority_queue<long long int> mainPQ;
vector<long long int> queueArray;
bool test(priority_queue<long long int> &PQ, long long int *b,
          long long int n) {
  for (long long int i = n; i >= 1; i--) {
    for (long long int j = 1; j <= b[i]; j++) {
      if (PQ.empty()) {
        return true;
      }
      long long int top = PQ.top();
      PQ.pop();
      if (top >= value2power[i + 1]) {
        return false;
      }
    }
  }
  if (PQ.empty()) {
    return true;
  } else {
    return false;
  }
}
bool cutoffRemain(long long int num, long long int n) {
  priority_queue<long long int> auxiliaryPQ;
  long long int size = queueArray.size();
  for (long long int i = 1; i <= size; i++) {
    auxiliaryPQ.push(queueArray[i - 1]);
  }
  for (long long int i = 1; i <= n; i++) {
    c[i] = a[i];
  }
  for (long long int i = 1; i <= n; i++) {
    if (c[i] > num) {
      for (long long int j = 1; j <= c[i] - num; j++) {
        auxiliaryPQ.push(value2power[i]);
      }
      c[i] = num;
    }
  }
  long long int temp = c[n];
  for (long long int i = n; i >= 2; i--) {
    c[i] = c[i - 1] - c[i];
  }
  for (long long int i = 1; i <= n - 1; i++) {
    c[i] = c[i + 1];
  }
  c[n] = temp;
  return test(auxiliaryPQ, c, n);
}
int main() {
  value2power[1] = 1;
  for (long long int i = 2; i <= 49; i++) {
    value2power[i] = 2 * value2power[i - 1];
  }
  long long int temp;
  cin >> m;
  for (long long int i = 1; i <= m; i++) {
    scanf("%lld", &temp);
    bool mark = true;
    for (long long int j = 1; j <= 49; j++) {
      if (temp == value2power[j]) {
        a[j]++;
        mark = false;
        break;
      }
    }
    if (mark) {
      queueArray.push_back(temp);
      mainPQ.push(temp);
    }
  }
  long long int n = 0;
  for (long long int i = 1; i <= 40; i++) {
    if (a[i] < a[i + 1]) {
      for (long long int j = 1; j <= a[i + 1] - a[i]; j++) {
        queueArray.push_back(value2power[i + 1]);
        mainPQ.push(value2power[i + 1]);
      }
      a[i + 1] = a[i];
    }
  }
  for (long long int i = 40; i >= 1; i--) {
    if (a[i] != 0) {
      n = i;
      break;
    }
  }
  if (mainPQ.size() > a[1]) {
    cout << -1;
  } else {
    bool v = cutoffRemain(a[1], n);
    if (v == false) {
      cout << -1;
    } else {
      long long int minremain = 0;
      long long int maxremain = a[1];
      while (minremain < maxremain) {
        long long int mid = (minremain + maxremain) / 2;
        if (cutoffRemain(mid, n)) {
          maxremain = mid;
        } else {
          minremain = mid + 1;
        }
      }
      for (long long int i = minremain; i <= a[1]; i++) {
        printf("%lld ", i);
      }
    }
  }
}
