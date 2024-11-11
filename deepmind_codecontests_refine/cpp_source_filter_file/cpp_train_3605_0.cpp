#include <bits/stdc++.h>
using namespace std;
void sortU(long long *a) {
  int tmp = 0;
  if (*a > *(a + 1)) {
    tmp = *a;
    *a = *(a + 1);
    *(a + 1) = tmp;
  }
}
int main() {
  long long volume = 0, capacity[2] = {}, tmp, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    volume += tmp;
  }
  tmp = 0;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    sortU(capacity);
    if (tmp > capacity[0])
      capacity[0] = tmp;
    else if (tmp > capacity[1])
      capacity[1] = tmp;
  }
  if (volume < capacity[0] + capacity[1]) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
