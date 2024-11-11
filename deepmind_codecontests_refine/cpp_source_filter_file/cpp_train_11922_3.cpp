#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, r, ans = 0, manys = 0;
  bool flag = false;
  map<int, int> object, temp;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l, &r);
    object[l * 2]++;
    object[r * 2 + 1]--;
  }
  for (map<int, int>::iterator object_it = object.begin();
       object_it != object.end(); object_it++) {
    ans += object_it->second;
    if (ans >= k && !flag) {
      l = object_it->first / 2;
      flag = true;
    } else if (ans < k && flag) {
      r = object_it->first / 2;
      if (r < 0) r--;
      manys++;
      temp[l] = r;
      flag = false;
    }
  }
  printf("%d\n", manys);
  for (map<int, int>::iterator temp_it = temp.begin(); temp_it != temp.end();
       temp_it++)
    printf("%d %d\n", temp_it->first, temp_it->second);
  return 0;
}
