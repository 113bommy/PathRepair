#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> pn;
vector<bool> is_p;

void enum_prime()
{
  is_p.resize(1515, true);
  is_p[0] = is_p[1] = false;
  for(int i = 2; i <= 1515; i++) {
    if(!is_p[i]) continue;
    pn.push_back(i);
    for(int j = i+i; j <= 1515; j+=i) is_p[j] = false;
  }
}

int dp[1200][300][15];

int solve(int n, int p, int k)
{
  if(k == 0 && n == 0) return 1;
  if(k < 0 || n < 0 || p < 0) return 0;  
  
  int& ret = dp[n][p][k];
  if(~ret) return ret;

  ret = solve(n, p - 1, k);
  if(n >= pn[p]) ret += solve(n - pn[p], p - 1, k - 1);

  return ret;
}

int main()
{
  enum_prime();
  int n, k;
  while(cin >> n >> k, n || k) {
    memset(dp, -1, sizeof(dp));
    int p = upper_bound(pn.begin(), pn.end(), n) - pn.begin() - 1;
    cout << solve(n, p, k) << endl;
  }
  return 0;
}