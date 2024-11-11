#include <bits/stdc++.h>
using namespace std;
int n, res = 1, tim = 0;
int main() {
  n = ({
    long long first = 0;
    int n = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) n = c == '-';
    for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
    n ? -first : first;
  });
  int lasx = 0, lasy = 0;
  for (int i = 1; i <= n; i++) {
    int first = ({
      long long first = 0;
      int n = 0, c = getchar();
      for (; !isdigit(c); c = getchar()) n = c == '-';
      for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
      n ? -first : first;
    }),
        second = ({
          long long first = 0;
          int n = 0, c = getchar();
          for (; !isdigit(c); c = getchar()) n = c == '-';
          for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
          n ? -first : first;
        });
    char c = ({
      char c = getchar();
      while (c == ' ' || c == '\n') c = getchar();
      c;
    });
    if (c == 'p') {
      if (first == 12)
        first = 12;
      else
        first += 12;
    } else {
      if (first == 12)
        first = 0;
      else
        ;
    }
    if ((lasx < first || (lasx == first && lasy < second))) {
      tim = 1;
    } else if (lasx == first && lasy == second && tim < 10)
      tim++;
    else
      res++, tim = 0;
    lasx = first, lasy = second;
    for (bool ___ = 1; ___; ___ = 0)
      ;
    {
      char c = getchar();
      while (c != '\n') c = getchar();
    }
  }
  cout << res;
}
