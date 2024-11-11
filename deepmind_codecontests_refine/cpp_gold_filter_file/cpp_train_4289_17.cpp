#include <bits/stdc++.h>
using namespace std;
int islucky(long long int a) {
  long long int temp = a;
  if (temp == 0) return 0;
  while (temp != 0) {
    if (temp % 10 != 4 && temp % 10 != 7) return 0;
    temp /= 10;
  }
  return 1;
}
int main() {
  long long int v[10010];
  memset(v, 0, sizeof(v));
  v[0] = 4;
  v[1] = 7;
  for (int end = 2, cnt = 0; end <= 1500; cnt++) {
    v[end++] = v[cnt] * 10 + 4;
    v[end++] = v[cnt] * 10 + 7;
  }
  long long int facto[15];
  long long int n, k;
  facto[0] = 1;
  for (int i = 1; i < 15; i++) facto[i] = facto[i - 1] * i;
  cin >> n >> k;
  k -= 1;
  long long int to_be_changed = 0;
  if (n <= 15)
    if (k >= facto[n]) {
      cout << -1 << endl;
      return 0;
    }
  for (to_be_changed = 1; to_be_changed <= 15; to_be_changed++)
    if (facto[to_be_changed] > k) break;
  long long int a[100];
  for (int l = 0; l < to_be_changed; l++) {
    a[l] = n - to_be_changed + l + 1;
  }
  long long int sum = 0;
  for (int i = 0; i <= 1500; i++) {
    if (v[i] >= (n - to_be_changed + 1)) break;
    sum += 1;
  }
  long long int size = to_be_changed;
  long long int perm_no = k;
  long long int r = perm_no;
  long long int m = 0;
  long long int position = 0;
  sort(a, a + size);
  while (position <= size - 1) {
    m = r / facto[size - 1 - position];
    r = r % facto[size - 1 - position];
    long long int t = *(a + position + m);
    *(a + position + m) = *(a + position);
    *(a + position) = t;
    sort(a + position + 1, a + size);
    position++;
    if (r == 0) break;
  }
  for (int i = 0; i < to_be_changed; i++) {
    sum += (islucky(a[i]) && islucky(n - size + i + 1));
  }
  cout << sum << endl;
  return 0;
}
