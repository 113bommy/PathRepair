#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
struct revenge {
  int a, b, count;
} shagun[MAX];
int n, p, k, i, position = -1;
long long int sum = 0;
multiset<int> s;
long long int priority[MAX];
bool compare1(const revenge &x, const revenge &y) {
  return x.b < y.b || (x.b == y.b && x.a > y.a);
}
bool compare2(const revenge &x, const revenge &y) { return x.a > y.a; }
int main() {
  scanf("%d %d %d", &n, &p, &k);
  for (i = 0; i < n; ++i) {
    scanf("%d %d", &shagun[i].a, &shagun[i].b);
    shagun[i].count = i + 1;
  }
  sort(shagun, shagun + n, compare1);
  priority[0] = shagun[0].b;
  for (i = 1; i < n; ++i) priority[i] = priority[i - 1] + shagun[i].b;
  for (i = n - 1; i > n - k; --i) {
    sum += shagun[i].a;
    s.insert(shagun[i].a);
  }
  pair<long long int, long long int> prev = make_pair(-1, -1);
  for (int i = n - k; i >= p - k; --i) {
    long long int temp = 0;
    if (p != k)
      temp = (i == p - k) ? priority[i - 1]
                          : priority[i - 1] - priority[i - p + k - 1];
    pair<long long int, long long int> current =
        make_pair(sum + shagun[i].a, temp);
    if (current > prev) {
      position = i;
      prev = current;
    }
    sum += shagun[i].a;
    s.insert(shagun[i].a);
    long long int lol = *s.begin();
    s.erase(s.begin());
    sum -= lol;
  }
  sort(shagun + position + 1, shagun + n, compare2);
  for (i = position - p + k; i <= position + k - 1; ++i)
    printf("%d ", shagun[i].count);
  return 0;
}
