#include <bits/stdc++.h>
using namespace std;
int ar[100100];
char br[100010];
int cr[100100];
int has[100010];
int main() {
  int n, ptr = 0, flag;
  cin >> n;
  cin >> br;
  for (int i = 0; i < n; i++) cin >> cr[i];
  while (1) {
    if (ptr < 0 || ptr > n) {
      flag = 1;
      break;
    }
    has[ptr]++;
    ;
    if (has[ptr] > 1) {
      flag = 2;
      break;
    }
    if (br[ptr] == '>') {
      ptr = ptr + cr[ptr];
    } else if (br[ptr] == '<') {
      ptr = ptr - cr[ptr];
    }
  }
  if (flag == 2)
    cout << "INFINITE\n";
  else if (flag == 1)
    cout << "FINITTE\n";
}
