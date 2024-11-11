#include<iostream>
#include<stdio.h>
using namespace std;

int primemax(int m);
int primemin(int m);

int main() {
	int n;
	while (scanf("%d",&n) != EOF) {
		cout << primemax(n - 1) << " " << primemin(n + 1) << endl;
	}
}

int primemax(int n)
{
	int t;
	for (n;; n--)
	{
		for (t = 2; t <= n; t++)
		{
			if (t == n)
			{
				return n;
			}
			else if (n%t == 0)
			{
				break;
			}
		}
	}
}
int primemin(int n)
{
	int t;
	for (n;; n++)
	{
		for (t = 2; t <= n; t++)
		{
			if (t == n)
			{
				return t;
			}
			else if (n%t == 0)
			{
				break;
			}
		}
	}
}