#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <sstream>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
template<class T> inline T sqr(T a) {return a * a;}
#define INF 123456789
#define MOD 1000000007
#define PRIME 1103
#define TEST "test"

int a[2000][2000];
bool was[2000][2000];
struct point 
{
	int x, y;
	point(){}
	point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};
int r = 0, q = 0;
int n;
int dx[4] = {0, 0, 1, -1},
	dy[4] = {-1, 1, 0, 0};


void dfs(const point &p)
{
	was[p.x][p.y] = 1;
	for(int i = 0; i < 4; ++i)
	{
		point t(p.x + dx[i], p.y + dy[i]);
		if(t.x < 0 || t.x >= n || 
			t.y < 0 || t.y >= n || was[t.x][t.y] ||
			!a[t.x][t.y]) continue;
		dfs(t);
	}
}


void dfs_c(point & p, bool used[2000][2000], int &count, point &c)
{
	was[p.x][p.y] = 1;
	++count;
	c.x += p.x;
	c.y += p.y;
	for(int i = 0; i < 4; ++i)
	{
		point t (p.x + dx[i], p.y + dy[i]);
		if(t.x < 0 || t.y < 0 ||
			t.x >= n || t.y >= n || 
			!a[t.x][t.y] || was[t.x][t.y])
			continue;
		dfs_c(t, used, count, c);
	}
}

int dx1[] = {0, 1, 1, 1, 0},
	dy1[] = {1, 1, 0, -1, -1};
void dfs_s(point & p, point & c, int &yes, int &no,
	double rad, bool used[2000][2000])
{
	used[p.x][p.y] = 1;
	double rad1 = sqrt(sqr(p.x - c.x) + sqr(p.y - c.y) + .0);
	if(abs(rad - rad1) < 4.)
		++yes;
	else ++no;
	for(int i = 0; i < 5; ++i)
	{
		point t (p.x + dx1[i], p.y + dy1[i]);
		if(t.x < 0 || t.y < 0 ||
			t.x >= n || t.y >= n ||
			!a[t.x][t.y] || used[t.x][t.y])
			continue;
		dfs_s(t, c, yes, no, rad, used);
		break;
	}
}

void f(const point &p)
{
	bool used[2000][2000] = {0};
	int count = 0;
	point c(0, 0);
	dfs_c(point(p), used, count, c);
	c.x /= count;
	c.y /= count;
	memset(used, 0, sizeof used);
	int yes = 0,
		no = 0;
	double rad = abs(p.x - c.x);
	dfs_s(point(p), c, yes, no, rad, used);
	if(!no)
		++r;
	else ++q;
	dfs(p);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen(TEST ".in", "r", stdin);
	freopen(TEST ".out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(!a[i][j] || was[i][j]) continue;
			f(point(i, j));
		}
	}
	cout << r << " "<< q;
	return 0;
}