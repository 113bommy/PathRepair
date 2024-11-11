#include<iostream>
#include<cstdio>
using namespace std;
#include<vector>
#include<math.h>
#include<queue>
#include<functional>

int n, m, s, g;
struct load{
	int x;
	int y;
	int d;
	int c;
};
struct P{
	double cost;
	int from;
	int now;
	int sp;
	bool operator > (const P& p) const{
		return cost > p.cost;
	}
};
//vector<vector<vector<double>>> vvvi;

double cost[31][31][31];//from now sp


int main(){


	while (cin >> n >> m, n | m){
		vector<load> L;
		cin >> s >> g;
		for (int i = 0; i < m; i++){
			int x, y, d, c;
			cin >> x >> y >> d >> c;
			L.push_back({ x, y, d, c });
			L.push_back({ y, x, d, c });
		}
		priority_queue<P, vector<P>, greater<P>> q;
		q.push({ 0.0, s, s, 0 });
		cost[s][s][0] = 0.0;

		for (int i = 0; i < 31; i++)
			for (int j = 0; j < 31; j++)
				for (int k = 0; k < 31; k++)
					cost[i][j][k] = 100000.0;

		while (!q.empty()){
			if (q.top().now == g &&q.top().sp == 1)break;
			P q2 = q.top();
			q.pop();
			for (int i = 0; i < (signed int)L.size(); i++){
				for (int j = -1; j < 2; j++){
					if (q2.now == L[i].x&&q2.from != L[i].y&& L[i].c >= q2.sp + j)
						if (q2.sp + j>0)
							if (q2.cost + L[i].d / (double)(q2.sp + (j)) < cost[q2.now][L[i].y][q2.sp + (j)]){
								q.push({ q2.cost + L[i].d / (double)(q2.sp + (j)), q2.now, L[i].y, q2.sp + (j) });
								cost[q2.now][L[i].y][q2.sp + (j)] = q2.cost + L[i].d / (double)(q2.sp + (j));
							}
				}
			}
		}
		if (!q.empty())printf("%.5lf\n", q.top().cost);
		else cout << "unreachable" << endl;
	}
	return 0;
}