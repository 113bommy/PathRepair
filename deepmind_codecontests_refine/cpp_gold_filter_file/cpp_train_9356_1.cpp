
#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

typedef pair<int, int> P;
vector<P> D;

int n, a, b;
int DP[101][101];

void solve()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i!=j) DP[i][j] = INT_MAX;
			else DP[i][j] = 0;
		}
	}	

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<n-i; j++)
		{
			for(int k=j; k<j+i; k++)
			{
				int cost = D[j].first * D[k].second * D[k+1].first * D[j+i].second;
				DP[j][j+i] = min(DP[j][j+i], cost + DP[j][k] + DP[k+1][j+i]);
			}
		}
	}

	cout << DP[0][n-1] << endl;
}

int main(int argc, char** argv)
{
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a >> b;
		P p(a, b);
		D.push_back(p);
	}

	solve();
}