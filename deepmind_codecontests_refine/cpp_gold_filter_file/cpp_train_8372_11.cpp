#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000 * 1000;
char s[MaxN];
int pos[MaxN];
int szPos = 0;
int main() {
  scanf("%s", s);
  int n = (int)strlen(s);
  for (int i = 0; i < n; i++)
    if (s[i] == '@' || s[i] == '.') pos[szPos++] = i;
  long long result = 0;
  for (int i = 0; i < szPos - 1; i++) {
    if (s[pos[i]] != '@' || s[pos[i + 1]] != '.') continue;
    int left = 0;
    if (i != 0) left = pos[i - 1] + 1;
    int right = n - 1;
    if (i != szPos - 2) right = pos[i + 2] - 1;
    int mid1 = pos[i];
    int mid2 = pos[i + 1];
    if (left >= mid1 || mid2 - mid1 <= 1 || right <= mid2) continue;
    bool ok = true;
    for (int j = mid1 + 1; j < mid2; j++)
      if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')))
        ok = false;
    if (!ok) continue;
    long long canLeft = 0;
    for (int j = mid1 - 1; j >= left; j--)
      if (s[j] >= 'a' && s[j] <= 'z') canLeft++;
    long long canRight = 0;
    for (int j = mid2 + 1; j <= right; j++)
      if (s[j] >= 'a' && s[j] <= 'z') {
        canRight++;
      } else
        break;
    result += canLeft * canRight;
  }
  printf("%lld", result);
}
