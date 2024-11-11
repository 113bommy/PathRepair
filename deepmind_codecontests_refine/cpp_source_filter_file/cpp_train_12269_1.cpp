#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int n;
pair<int,int> x[200010];
multiset<int> b,r;
ll ans;
int main()
{
	cin>>n; 
    for (int i=1;i<=n;i++)
    {
        cin>>x[i].first>>x[i].second;
        if (x[i].first>x[i].second) swap(x[i].first,x[i].second);
        b.insert(x[i].first),r.insert(x[i].second);
    }
    ans=(b.rbegin()-*b.begin())*(*r.rbegin()-*r.begin());
    sort(x+1,x+n+1);
    for (int i=1;i<=n;i++)
    {
        b.erase(b.find(x[i].first)),r.insert(x[i].first);
        r.erase(r.find(x[i].second)),b.insert(x[i].second);
        ans=min(ans,1LL*(*b.rbegin()-*b.begin())*(*r.rbegin()-*r.begin()));
    }
    cout<<ans;
    return 0;
}