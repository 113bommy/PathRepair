#include <iostream>
#include <cstdlib>
#include <string>
#include <memory.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1 << 29;

const int MAX_N = 1000010;
ll euler[MAX_N];
ll s[MAX_N];

void euler_phi(){
  rep(i, MAX_N) euler[i] = i;
  for(int i = 2; i < MAX_N; i++){
    if(euler[i] == i){
      for(int j = i; j < MAX_N; j += i) euler[j] = euler[j] / i * (i - 1);
    }
  }
}

int main(){
  euler_phi();
  s[0] = euler[0] + 1;
  for(int i = 1; i < MAX_N; i++) s[i] = s[i-1] + euler[i];
  int t, n;
  cin >> t;
  rep(i, t){
    cin >> n;
    cout << s[n] << endl;
  }
  return 0;
}