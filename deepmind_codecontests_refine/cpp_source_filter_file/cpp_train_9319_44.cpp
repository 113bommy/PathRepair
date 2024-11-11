#include <bits/stdc++.h>
using namespace std;
double res;
long long n;
int i;
long long a[1001];
long long b[1001];
bool flag[1000001];
bool flag2[1000001];
bool flag3[1000001];
vector<long long> numbers;
vector<long long> numbers2;
int cnt, cnt2;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    numbers.push_back(a[i]);
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
    numbers2.push_back(b[i]);
  }
  while (numbers.size() != 0) {
    i = 0;
    cnt2 = 0;
    while (numbers[i] != 0) {
      if (numbers[i] & 1 == 1) {
        flag[cnt2++] = 1;
      } else {
        cnt2++;
      }
      numbers[i] = numbers[i] >> 1;
    }
    i++;
    numbers.erase(numbers.begin(), numbers.begin() + i);
    cnt = max(cnt, cnt2);
  }
  for (int i = 0; i < cnt; i++) {
    if (flag[i]) res += pow(2, i);
  }
  while (numbers2.size() != 0) {
    i = 0;
    cnt2 = 0;
    while (numbers2[i] != 0) {
      if (numbers2[i] & 1 == 1) {
        flag2[cnt2++] = 1;
      } else {
        cnt2++;
      }
      numbers2[i] = numbers2[i] >> 1;
    }
    i++;
    numbers2.erase(numbers2.begin(), numbers2.begin() + i);
    cnt = max(cnt, cnt2);
  }
  for (int i = 0; i < cnt; i++) {
    if (flag2[i]) {
      res += pow(2, i);
    }
  }
  cout << res;
  return 0;
}
