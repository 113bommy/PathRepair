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
int t[110000];
bool used[110000];
int main() {
  int n, m;
  int i, j, k;
  int a, b, c;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (i = 0; i < n; i++) {
    used[t[i]] = true;
    if (t[i] > i + 1) {
      cout << -1 << endl;
    }
  }
  for (i = n; i > 0; i--) {
    t[i] = t[i - 1];
  }
  for (i = 0; i < n; i++) {
    if (t[i] == t[i + 1]) t[i] = -1;
  }
  for (i = 0, j = 0; i < n; i++) {
    if (t[i] != -1) continue;
    while (used[j]) j++;
    t[i] = j;
    used[j] = true;
  }
  array_show(t, n);
}
