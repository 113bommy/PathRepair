#include <bits/stdc++.h>
using namespace std;
void scanint(long long int &x) {
  register long long int c = getchar();
  x = 0;
  long long int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline void Print_f(long long n) {
  char buffer[sizeof(n) * 8 * 3 / 10 + 3];
  int index = sizeof(buffer) - 1;
  int end = index;
  buffer[index--] = 0;
  do {
    buffer[index--] = (n % 10) + '0';
    n /= 10;
  } while (n);
  puts(&buffer[index + 1]);
}
int main() {
  bool zero_flag = false;
  long long int n = 0, exp = 0, l = 0, i = 0;
  scanint(n);
  char in[100003], val[100003];
  val[0] = '1', val[1] = '\0';
  while (n--) {
    cin >> in;
    if (!zero_flag) {
      l = strlen(in);
      if (l == 1 && in[0] == '0')
        zero_flag = true;
      else {
        for (i = (l - 1); i >= 0; i--) {
          if (in[i] != '0')
            break;
          else
            exp++;
        }
        if (i || (l == 1 && in[i] != '1')) in[i + 1] = '\0', strcpy(val, in);
      }
    }
  }
  if (zero_flag)
    cout << "0";
  else {
    cout << val;
    for (long long int i = 0; i < exp; i++) cout << "0";
  }
  cout << endl;
  return 0;
}
