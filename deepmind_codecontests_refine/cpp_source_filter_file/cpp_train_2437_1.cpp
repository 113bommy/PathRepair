#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
  int n;
  int mini = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[mini] > a[i]) mini = i;
  }
  swap(a[mini], a[n - 1]);
  int maxi = 0;
  for (int i = 0; i < n - 1; i++)
    if (a[maxi] < a[i]) maxi = i;
  swap(a[0], a[maxi]);
  sort(a + 1, a + n - 2);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
