#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
#define PI 3.1415926535897932384626433832795028
#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

Int x_1, y_1, x_2, y_2;
Int n;
Int x[216000], y[216000];
vector<P> nums;
int main(){
  cin >> x_1 >> y_1 >> x_2 >> y_2;
  if(x_1 > x_2){
    swap(x_1, x_2);
    swap(y_1, y_2);
  }
  cin >> n;
  for(int i = 0;i < n;i++)cin >> x[i] >> y[i];

  if(y_1 > y_2){
    y_1 = -y_1;
    y_2 = -y_2;
    for(int i = 0;i < n;i++)y[i] *= -1;
  }

  for(int i = 0;i < n;i++){
    if(x[i] < x_1 || x_2 < x[i])continue;
    if(y[i] < y_1 || y_2 < y[i])continue;
    nums.push_back(P(x[i], y[i]));
  }
  sort(nums.begin(), nums.end());
  vector<int> dp(n, INF);
  for(int i = 0;i < nums.size();i++){
    int val = nums[i].second;
    *upper_bound(dp.begin(), dp.end(), val) = val;
  }
  int cnt = 0;
  while(cnt < n && dp[cnt] != INF)cnt++;
  double ans;
  ans = (x_2 - x_1 + y_2 - y_1) * 100 + cnt * (5 * PI - 20);
  
  if(min(x2 - x1,y2- y1) + 1 == cnt){
    ans -= 5 * PI - 20;
    ans += 10 * PI - 20;
  }

  printf("%.10lf\n", ans);
  
  return 0;
}