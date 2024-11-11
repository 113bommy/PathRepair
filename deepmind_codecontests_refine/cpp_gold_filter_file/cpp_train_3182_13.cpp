#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n;
int a[101];
char b[] = {'a', 'e', 'i', 'o', 'u', 'y'};
string s;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    int cnt = 0;
    for (int j = 0; j < s.size(); j++)
      for (int k = 0; k < 6; k++)
        if (s[j] == b[k]) {
          cnt++;
          if (cnt > a[i]) {
            j = s.size();
            break;
          }
        }
    if (cnt != a[i]) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
}
