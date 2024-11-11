//ギブアップ 2019/11/8
//key 二分探索
#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
int n;
ll k;
std::cin >> n>>k;
std::vector<int> a(n);
std::vector<int> f(n);

for (int i = 0; i < n; i++)std::cin >> a[i];
for (int i = 0; i < n; i++)std::cin >> f[i];

sort(a.begin(),a.end());
sort(f.begin(),f.end(),std::greater<int>());

ll l=-1,r=1e12;
ll  c;
ll  s;
while (1+l<r) {
      c=(l+r)/2;
      s=0;
      for (int i = 0; i < n; ++i) {
        s+=max(a[i]-c/f[i],(ll)0);
      }
      if(s<=k)r=c;else l=c;
}

std::cout << r << '\n';

return 0;
}
