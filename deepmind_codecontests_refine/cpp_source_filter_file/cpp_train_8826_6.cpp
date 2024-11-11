#include<iostream>
#include<vector>
int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> cnt(n + 1), sum(n + 1), ans(n);
  for(int i = 0; i != n; ++i){
    int a;
    std::cin >> a;
    ++sum[cnt[a]++];
  }
  int it = 0, acc = 0;
  for(int t = n; t != 0; --t){
    while(acc >= it * t)
      acc += sum[it++];
    ans[t - 1] = it - 1;
  }
  for(const int e : ans)
    std::cout << e << '¥n';
}
