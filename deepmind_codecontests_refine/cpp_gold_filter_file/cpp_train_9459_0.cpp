#include <iostream>
#include <algorithm>

#define int long long

signed main()
{
  int n;
  std::cin >> n;
  
  std::pair<int, int> a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i].first;
    a[i].second = i%2;
  }
  
  std::sort(a, a+n);
  
  int ans = 0;
  for(int i = 0; i < n; i++)
    ans += (i%2 != a[i].second);
  
  std::cout << ans/2 << std::endl;
  return 0;
}
