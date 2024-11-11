#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
int main()
{
	stack<double> s;
	double a, b;
	char c[80], bf;
	while (std::cin >> c)
	{
		if (c[0] == '+')
		{
			b = s.top(), s.pop();
			a = s.top(), s.pop();
			s.push(a+b);
		}
		else if (c[0] == '-' && c[1] == 0)
		{
			b = s.top(), s.pop();
			a = s.top(), s.pop();
			s.push(a-b);
		}
		else if (c[0] == '*')
		{
			b = s.top(), s.pop();
			a = s.top(), s.pop();
			s.push(a*b);
		}
		else if (c[0] == '/')
		{
			b = s.top(), s.pop();
			a = s.top(), s.pop();
			s.push(a/b);
		}
		else
		{
			s.push(atof(c));
		}
		if ((bf = getchar()) == '\n')
			printf("%.6f\n", s.top());
		if (bf == -1)
			return 0;
	}
}