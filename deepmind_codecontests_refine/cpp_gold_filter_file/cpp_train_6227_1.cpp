#include<bits/stdc++.h>
using namespace std;

int main()
{
long long n,m;
  cin >> n >> m;
  vector<pair<long long,long long> > P;
  for(int i = 0; i < n; i++)
    {
    long long a,b;
    cin >> a >> b;
    P.push_back({a,b});
    }
  sort(P.begin(), P.end());
  long long ans = 0;
  for(int i=0; i< n; i++){
    long long  mn  = min(P[i].second, m);
    m -= mn;
    ans += mn*P[i].first;
    }
  cout << ans << endl;
}
