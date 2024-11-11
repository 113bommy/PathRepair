#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, k, i, count = 0;
  cin >> n >> k;
  long long arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    count += arr[i];
  }
  float avrg = (float)count / n;
  long Int = (int)avrg;
  float average = (float)avrg;
  if (average >= k || (((2 * average) >= (2 * Int + 1))) && (Int + 1 >= k)) {
    cout << "0";
    return 0;
  } else {
    for (i = 0; i < 10000; i++) {
      count += k;
      n++;
      avrg = (float)count / n;
      average = (float)avrg;
      Int = (int)avrg;
      if (average >= k ||
          (((2 * average) >= (2 * Int + 1))) && (Int + 1 >= k)) {
        cout << i + 1;
        return 0;
      }
    }
  }
}
