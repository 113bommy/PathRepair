#include <bits/stdc++.h>
using namespace std;
void testcase();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(15);
  cout << fixed;
  long long t;
  cin >> t;
  while (t--) testcase();
  return 0;
}
typedef struct element {
  long long data;
  char color;
} box;
void testcase() {
  long long n;
  cin >> n;
  box a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i].data;
  }
  char color[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i].color;
  }
  box blue[n];
  box red[n];
  long long redindex = 0;
  long long blueindex = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i].color == 'B') {
      blue[blueindex] = a[i];
      blueindex++;
    } else if (a[i].color == 'R') {
      red[redindex] = a[i];
      redindex++;
    }
  }
  long long rednumber[n + 2], bluenumber[n + 2];
  for (long long i = 0; i < n + 2; i++) {
    rednumber[i] = 0;
    bluenumber[i] = 0;
  }
  for (long long i = 0; i < blueindex; i++) {
    if (blue[i].data <= 0) {
      bluenumber[0]++;
    } else if (blue[i].data > n) {
      bluenumber[n + 1]++;
    } else {
      bluenumber[blue[i].data]++;
    }
  }
  for (long long i = 0; i < redindex; i++) {
    if (red[i].data <= 0) {
      rednumber[0]++;
    } else if (red[i].data > n) {
      rednumber[n + 1]++;
    } else {
      rednumber[red[i].data]++;
    }
  }
  for (long long i = 1; i < n + 2; i++) {
    bluenumber[i] += bluenumber[i - 1];
  }
  for (long long i = n; i >= 0; i--) {
    rednumber[i] += rednumber[i + 1];
  }
  long long flag = 1;
  for (long long i = 0; i < n + 2; i++) {
    if (bluenumber[i] > i) {
      flag = 0;
    }
    if (rednumber[i] > (n + 1 - i)) {
      flag = 0;
    }
  }
  if (0 == flag) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
