#include <bits/stdc++.h>
using namespace std;
int n, vet[303030];
multiset<int> val;
long long sum;
int main() {
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); (i)++)
    scanf("%d", vet + i), sum += vet[i], val.insert(vet[i]);
  if (sum & 1) {
    puts("NO");
    return 0;
  }
  sum /= 2;
  if (val.count(sum)) {
    puts("YES");
    return 0;
  }
  long long cur = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    cur += vet[i];
    val.erase(val.find(vet[i]));
    if (cur > sum) continue;
    if (cur == sum) {
      puts("YES");
      return 0;
    }
    if (val.count(sum - cur)) {
      puts("YES");
      return 0;
    }
  }
  for (int(i) = (0); (i) < (n); (i)++) val.insert(vet[i]);
  reverse(vet, vet + n);
  cur = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    cur += vet[i];
    val.erase(val.find(vet[i]));
    if (cur > sum) continue;
    if (cur == sum) {
      puts("YES");
      return 0;
    }
    if (val.count(sum - cur)) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}
