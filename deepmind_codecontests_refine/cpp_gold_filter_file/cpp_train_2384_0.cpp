#include<iostream>
#include<algorithm>
using namespace std;

#define col first
#define cn second

typedef pair<int, int> PR;

pair<int, int> puyo[10000+10] , tmp;

int sum;


int chek(int , /*PR[10000 + 10],*/ int ,int,int);


int main()
{
	int n;
	int pn=0;

	int a;

	int i;

	int sa=0;

	while (cin >> n, n != 0)
	{
		sa = 0;
		sum = n;
		pn = 0;

		cin >> a;
		puyo[pn].col = a;
		puyo[pn].cn = 1;


		for (i = 1; i < n; i++)
		{
			cin >> a;

			if (puyo[pn].col == a)
			{
				puyo[pn].cn++;
			}
			else
			{
				pn++;
				puyo[pn].col = a;
				puyo[pn].cn = 1;
			}
		}

		pn++;

		for (i = 1; i < pn - 1; i++)
		{

			if (puyo[i].cn == 3)
			{
				if (puyo[i + 1].col == puyo[i - 1].col && puyo[i + 1].cn + puyo[i - 1].cn >= 5)
				{
					//tmp = puyo[i + 1];
					//puyo[i + 1].cn--;

					sa = 3 + puyo[i + 1].cn + puyo[i - 1].cn;

					sum = min(sum, n - chek(pn, i - 2, i + 2, sa));
					//puyo[i + 1] = tmp;
				}
			}

			if( puyo[i+1].cn==1 && puyo[i].col == puyo[i+2].col )
			{
				if (puyo[i].cn + puyo[i + 2].cn >= 3)
				{
					//puyo[i + 1].cn--;
					sa = 1 + puyo[i].cn + puyo[i + 2].cn;

					sum = min(sum, n - chek(pn, i - 1, i + 3, sa));
					
				}
			}
/*
			if (puyo[i - 1].cn == 1 && puyo[i].col == puyo[i - 2].col)
			{
				if (puyo[i].cn + puyo[i - 2].cn >= 3)
				{
					//puyo[i - 1].cn--;
					sa = 1 + puyo[i].cn + puyo[i - 2].cn;

					sum = min(sum, n - chek(pn, i - 3, i + 1, sa));
				}
			}
*/
			
		}
		
		cout << sum << endl;
	}
	return 0;
}


int chek(int pn/*, PR tp[10000 + 10]*/, int go, int ba , int sa)
{
	if (puyo[go].col == puyo[ba].col && puyo[go].cn + puyo[ba].cn >= 4)
	{
		sa += puyo[go].cn + puyo[ba].cn;

		if (go - 1 >= 0 && ba + 1 < pn)
		{
			return chek(pn, go - 1, ba + 1, sa);
		}

	}

	return sa;
}