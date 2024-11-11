#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long int MAX = 1e9 + 7;
void array_show(int *array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%d%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(long long int *array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%lld%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(vector<int> &vec_s, int vec_n = -1, char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%d%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
void array_show(vector<long long int> &vec_s, int vec_n = -1,
                char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%lld%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
string sa, sb, ss;
int num[3300000];
int z[3300000];
int main() {
  int n, m;
  int i, j, k;
  int a, b, c;
  cin >> n;
  n--;
  cin >> sa >> sb;
  for (i = 0; i < n; i++) {
    if (sa[i] == 'N') num[n - i - 1] = 0;
    if (sa[i] == 'E') num[n - i - 1] = 1;
    if (sa[i] == 'W') num[n - i - 1] = 2;
    if (sa[i] == 'S') num[n - i - 1] = 3;
  }
  for (i = 0; i < n; i++) {
    if (sb[i] == 'N') num[n + i] = 3;
    if (sb[i] == 'E') num[n + i] = 2;
    if (sb[i] == 'W') num[n + i] = 1;
    if (sb[i] == 'S') num[n + i] = 0;
  }
  for (i = 1, j = 0; i < n * 2;) {
    for (; j < n && i + j < 2 * n; j++) {
      if (num[i] != num[j]) break;
    }
    z[i] = j;
    if (j == 0) {
      i++;
      continue;
    }
    for (k = 1;; k++) {
      i++, j--;
      if (z[k] < j)
        z[i] = z[k];
      else
        break;
    }
  }
  for (i = n; i < n * 2; i++) {
    if (z[i] + i >= 2 * n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
