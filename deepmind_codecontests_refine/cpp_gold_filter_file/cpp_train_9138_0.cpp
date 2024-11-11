#include <bits/stdc++.h>
#define MAX 234
using namespace std;

int N;
char str[MAX];
int color[MAX];
int graph[MAX][MAX];
int depth[MAX];

int bfs(int cur)
{
	queue<int> q;
	q.push(cur);
	color[cur] = 0;
	depth[cur] = 0;
	int ret = 0;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int i = 0; i < N; i++)
		{
			if (graph[cur][i])
			{
				if (color[i] == color[cur])
				{
					cout << -1 << endl;
					exit(0);
				}
				if (color[i] < 0)
				{
					q.push(i);
					color[i] = !color[cur];
					depth[i] = depth[cur] + 1;
					ret = depth[i];
				}
			}
		}
	}
	return ret;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++) graph[i][j] = str[j] - '0';
	}
	int mmax = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			depth[j] = -1;
			color[j] = -1;
		}
		mmax = max(mmax, bfs(i));
	}
	cout << mmax + 1 << endl;
	return 0;
}
