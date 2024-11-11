#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main(void) {
  long long n;
  long long i, j;
  long long temp;
  long long min = 999999999;
  long long answer;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> temp;
    if (temp == 0)
      a[i] = i;
    else if (temp - (i - 1) <= 0)
      a[i] = i;
    else {
      temp = temp - (i - 1);
      a[i] = i;
      a[i] += temp / n * n;
      if (temp % n != 0) a[i] += n;
    }
    if (a[i] < min) {
      min = a[i];
      answer = i;
    }
  }
  cout << answer << endl;
  return 0;
}
