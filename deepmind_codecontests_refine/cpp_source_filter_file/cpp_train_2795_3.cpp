#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x - 1; i < y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i - - )
#define eps 1e - 9
#define all(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == ' - ') f =  - 1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
typedef pair<int,int> P;
 
int n;
ll l[100001],r[100001];
multiset<ll> L, R;
 
int main()
{
	n = read();
	rep(i, 1, n)
		scanf("%lld%lld",&l[i],&r[i]);
	
	L.insert( - 1LL << 60);
	R.insert(1LL << 60);
	ll ol = 0, Or = 0;
	ll res = 0;
	rep(i, 1, n)
	{
		if(i > 0) ol  - = r[i] - l[i], Or += r[i - 1] - l[i - 1];
		if(l[i] < *L.rbegin() + ol) res += *L.rbegin() + ol - l[i];
		else if(*R.begin() + Or < l[i]) res += l[i] - (*R.begin() + Or);
		if(l[i]<*L.rbegin() + ol)
		{
			R.insert(*L.rbegin() + ol - Or);
			L.insert(l[i] - ol);
			L.insert(l[i] - ol);
			L.erase(L.find(*L.rbegin()));
		}
		else if(*R.begin() + Or < l[i])
		{
			L.insert(*R.begin() + Or - ol);
			R.insert(l[i] - Or);
			R.insert(l[i] - Or);
			R.erase(R.begin());
		}
		else
		{
			L.insert(l[i] - ol);
			R.insert(l[i] - Or);
		}
	}
	printf("%lld\n",res);
	return 0;
}
