#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back

using namespace std;

int ans[10];

void solve(vector<int> a,int n)
{
	int count = 0;
	rep(i,a.size()) count += a[i];

	if(count == 0)
	{
		ans[n] = 1;
		return;
	}

	REP(i,1,10)
	{
		if(a[i] >= 3)
		{
			a[i] -= 3;
			solve(a,n);
			a[i] += 3;
		}
	}

	REP(i,3,10)
	{
		if(a[i-2] && a[i-1] && a[i])
		{
			a[i-2]--; a[i-1]--; a[i]--;
			solve(a,n);
			a[i-2]++; a[i-1]++; a[i]++;
		}
	}
}


int main()
{
	string s;
	while(cin >> s)
	{
		vector<int> a;
		memset(ans,0,sizeof(ans));

		rep(i,10) a.pb(0);
		rep(i,s.size()) a[s[i] - '0']++;

		REP(i,1,10)
		{
			if(a[i] == 4)
			{
				continue;
			}
			else
			{
				a[i]++;
				REP(i,1,10)
				{
					if(a[j] >= 2)
					{
						a[j] -= 2;
						solve(a,i);
						a[j] += 2;
					}
				}
				a[i]--;
			}
		}

		bool count_0 = true;
		int ans_max = 0;
		REP(i,1,10)
		{
			if(ans[i])
			{
				count_0 = false;
				ans_max = max(ans_max,i);
			}
		}

		if(count_0) 
		{
			cout << 0 << endl;
		}
		else
		{
			bool flag = true;
			REP(i,1,10)
			{
				if(ans[i] == 1)
				{
					if(i == ans_max)
					{
						cout << i << endl;
					}
					else
					{
						cout << i << " ";
					}
				}
			}
		}
	}
	return 0;
}