#include <bits/stdc++.h>
using namespace std;
int main() {
  long n = ({
    long a;
    scanf("%ld", &a);
    a;
  }),
       m = ({
         long a;
         scanf("%ld", &a);
         a;
       });
  long arr[100] = {0};
  for (long i = 1; i <= m; i++) {
    long t = ({
      long a;
      scanf("%ld", &a);
      a;
    });
    for (long j = t; j <= n; j++) {
      if (arr[j] == 0) arr[j] = t;
    }
  }
  for (long i = 1; i <= n; i++) printf("%ld ", arr[i]);
  return 0;
}
