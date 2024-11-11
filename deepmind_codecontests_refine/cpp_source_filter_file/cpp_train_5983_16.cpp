#include <bits/stdc++.h>
using namespace std;
void fun(int& calc, char first, char second) {
  if (second > first) {
    calc += min(second - first, first + 26 - second);
    return;
  } else {
    calc += min(first - second, second + 26 - first);
    return;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  k--;
  string s;
  cin >> s;
  if (k >= n / 2) {
    reverse(s.begin(), s.end());
    k = n - k - 1;
  }
  int calc = 0;
  int front = 0;
  int rear = n / 2 - 1;
  int mid = n / 2;
  while (rear >= 0 && s[rear] == s[n - rear - 1]) {
    rear--;
  }
  while (front < mid && s[front] == s[n - front - 1]) {
    front++;
  }
  if (front > rear) {
    cout << calc << endl;
    return 0;
  }
  for (int i = front; i <= rear; i++) {
    fun(calc, s[i], s[n - i - 1]);
  }
  if ((k > rear && front != rear) || (k < rear && k > front)) {
    calc += (rear - front) + min((rear - k), (k - front));
    cout << calc << endl;
    return 0;
  }
  if (k == front && front != rear) {
    calc += abs(k - rear);
    cout << calc << endl;
    return 0;
  }
  if (k == rear && front != rear) {
    calc += abs(k - front);
    cout << calc << endl;
    return 0;
  }
  if (k <= front || (front == rear)) {
    calc += abs(rear - k);
    cout << calc << endl;
    return 0;
  }
  cout << calc << endl;
}
