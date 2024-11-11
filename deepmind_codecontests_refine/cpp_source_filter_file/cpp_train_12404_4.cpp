#include <bits/stdc++.h>
using namespace std;
int a[1007], b[1007];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n1, n2, start;
  cin >> n1 >> n2 >> start;
  for (int i = 0; i < n1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n2; i++) {
    cin >> b[i];
  }
  sort(a, a + n1);
  sort(b, b + n2);
  int s = start;
  int k = 0;
  while (start >= a[0]) {
    start -= a[0];
    k++;
  }
  int sum = 0;
  while (k != 0) {
    sum += b[n2 - 1];
    k--;
  }
  if (s > sum)
    cout << s << endl;
  else
    cout << sum + start << endl;
  return 0;
}
