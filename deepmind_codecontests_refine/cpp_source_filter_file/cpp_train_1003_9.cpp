#include <bits/stdc++.h>
using namespace std;
int a[100];
void move(int n) {
  int top = a[0], pos = 0, temp;
  for (int i = 1; i < n; i++)
    if (a[i] > top) top = a[i], pos = i;
  temp = a[pos];
  for (int i = pos; i < n - 1; i++) a[i] = a[i + 1];
  a[n] = temp;
}
bool check(int n) {
  for (int i = 1; i < n; i++)
    if (a[i - 1] - 2 <= a[i]) return false;
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = n - 1; i >= 0; i--) {
    if (check(n)) {
      cout << "NO" << endl;
      return 0;
    }
    move(i);
  }
  cout << "YES" << endl;
}
