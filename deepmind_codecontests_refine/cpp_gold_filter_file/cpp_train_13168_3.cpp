#include <bits/stdc++.h>
using namespace std;
typedef struct hi {
  char sb;
  int p;
  int s;
} hi;
int main() {
  int n, sq;
  cin >> n >> sq;
  hi lol[n];
  for (int i = 0; i < n; i++) {
    cin >> lol[i].sb >> lol[i].p >> lol[i].s;
  }
  long long si[100001] = {0};
  long long bi[100001] = {0};
  for (int i = 0; i < n; i++) {
    if (lol[i].sb == 'S') {
      si[lol[i].p] += lol[i].s;
    } else {
      bi[lol[i].p] += lol[i].s;
    }
  }
  int count = 0;
  hi qwerty[sq];
  for (int i = 0; i <= 100000; i++) {
    if (si[i] != 0) {
      qwerty[count].sb = 'S';
      qwerty[count].p = i;
      qwerty[count].s = si[i];
      count++;
      if (count == sq) break;
    }
  }
  for (int i = count - 1; i >= 0; i--) {
    cout << qwerty[i].sb << " " << qwerty[i].p << " " << qwerty[i].s << endl;
  }
  int count1 = 0;
  for (int i = 100000; i >= 0; i--) {
    if (bi[i] != 0) {
      cout << "B " << i << " " << bi[i] << endl;
      count1++;
      if (count1 == sq) break;
    }
  }
  return 0;
}
