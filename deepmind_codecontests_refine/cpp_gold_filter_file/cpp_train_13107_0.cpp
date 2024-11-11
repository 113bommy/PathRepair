
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

typedef long long int lli;

lli a, b, c;
lli p, q, r, s;

bool solve()
{
	if(a == 0) return false;
	
	if(c == 0)
	{
		if(a != 1)
		{
			p = a;
			q = b;
			r = 1;
			s = 0;
			return true;
		}
		else
		{
			p = 1;
			q = max(b, (lli)0);
			r = 1;
			s = min(b, (lli)0);
			return true;
		}
	}

	for(lli i=1; i<=a; i++)
	{
		if(i * i > a) break;

		if(a%i==0)
		{
			p = a / i;
			r = i;
			for(lli j=1; j<=abs(c); j++)
			{
				if(c%j==0)
				{
					lli qt = c / j;
					lli st = j;
					if(p * st + r * qt == b)
					{
						q = qt;
						s = st;
						if(p == r) q = max(qt, st), s = min(qt, st);
						return true;
					}
					else if(p * qt + r * st == b)
					{
						q = st;
						s = qt;
						if(p == r) q = max(qt, st), s = min(qt, st);
						return true;
					}
					else if(- p * st - r * qt == b)
					{
						q = -qt;
						s = -st;
						if(p == r) q = max(-qt, -st), s = min(-qt, -st);
						return true;
					}
					else if(- p * qt - r * st == b)
					{
						q = -st;
						s = -qt;
						if(p == r) q = max(-qt, -st), s = min(-qt, -st);
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

int main()
{
	while( 1 )
	{
		cin >> a >> b >> c;
		if(a==0 && b==0 && c==0) break;
		if(solve()) printf("%lld %lld %lld %lld\n", p, q, r, s);
		else printf("Impossible\n");
	}
}