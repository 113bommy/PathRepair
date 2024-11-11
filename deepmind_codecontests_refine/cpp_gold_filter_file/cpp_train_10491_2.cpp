#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long int mod = 1e9 + 7;
long long int  n,m;
long long int a[200005];
bool cmp(int x, int y)
{
	return abs(x) < abs(y);
}
int main()
{
	int pn=0 ,nn = 0;
	//pn正数，nn负数；
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] >= 0)
			pn++;
		else
			nn++;
	}
	int l=1, r=n;//左右逼近
	long long ans = 1;
	if (!pn && m % 2 == 1)//结果必定为负数
	{
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= m; i++) 
			ans = a[i] * ans % mod;
	}
	else
	{
		sort(a + 1, a + 1 + n, greater< int >());
			////内置类型的由大到小排序
		while (m)
		{
			if (m % 2 == 1)//为奇数就乘大的正数
			{
				ans = ans * a[l] % mod;
				l++, m--;
			}
			else
			{
				if (a[l] * a[l + 1] >= a[r] * a[r - 1])
					//两正数乘起来比负数大
				{
					ans = ans * a[l] % mod * a[l + 1] % mod;
					l += 2,m -= 2;
				}
				else
				{
					ans = ans * a[r - 1] % mod * a[r] % mod;
					r -= 2,m -= 2;
				}
			}

		}
	}
	//防止出现负数，故再加mod再取余数
	cout << (ans % mod + mod) % mod << endl;
}