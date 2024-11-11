#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int Maxn = 1000005;
 
int t;
int n, a, b;
int seq[Maxn], slen;
 
int main()
{
    scanf("%d %d %d", &n, &a, &b);
    if (a + b - 1 > n || ll(a) * b < n) printf("-1\n");
    else {
      slen = 0;
      int cur = 1;
      int lft = n - a;
      for (int i = 1; i <= a; i++) {
        int tk = min(lft, b - 1); lft -= tk;
        tk++;
        cur += tk;
        for (int j = cur - 1; j >= cur - tk; j--)
          seq[slen++] = j;
      }
      for (int i = 0; i < slen; i++)
        printf("%d%c", seq[i], i + 1 < slen? ' ': '\n');
    }
}