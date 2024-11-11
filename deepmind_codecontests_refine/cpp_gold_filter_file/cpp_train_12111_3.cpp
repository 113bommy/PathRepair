#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
const long long INF = 8e18;
const long long MOD = 1e9 + 7;
int main() {
  long long n;
  long long m;
  cin >> n >> m;
  long long inp[n];
  for (int i = 0; i < n; i++) {
    cin >> inp[i];
  }
  sort(inp, inp + n);
  vector<long long> cnt;
  int num = 0;
  int j;
  for (int i = 0; i < n; i++) {
    num = 0;
    j = i;
    while (inp[i] == inp[j]) {
      num++;
      j++;
    }
    for (int k = 0; k < num; k++) cnt.push_back(num);
    i += num - 1;
  }
  long long maghsoom = m / n;
  long long baghimande = m % n;
  if (baghimande == 0) {
    baghimande = n;
    int j = maghsoom - 1 - 1;
    int i = maghsoom - 1;
    int times = 0;
    while (inp[i] == inp[j]) {
      times++;
      j--;
    }
    baghimande = baghimande + (n * times) - 1;
    long long sum = 0;
    int x = cnt[i];
    cout << inp[maghsoom - 1] << ' ';
    for (int i = 0; i < n; i++) {
      sum += x * cnt[i];
      if (sum > baghimande) {
        cout << inp[i];
        break;
      } else
        i += cnt[i] - 1;
    }
  } else {
    long long sum = 0;
    int j = maghsoom - 1;
    int i = maghsoom;
    int times = 0;
    while (inp[i] == inp[j]) {
      times++;
      j--;
    }
    int x = cnt[i];
    baghimande = baghimande + (n * times) - 1;
    cout << inp[maghsoom] << ' ';
    for (int i = 0; i < n; i++) {
      sum += x * cnt[i];
      if (sum > baghimande) {
        cout << inp[i];
        break;
      } else
        i += cnt[i] - 1;
    }
  }
  return 0;
}
