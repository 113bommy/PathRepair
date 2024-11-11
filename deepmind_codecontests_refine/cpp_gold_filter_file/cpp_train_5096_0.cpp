#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct {
	int to;
	int D;
	int E;
} Edge;

class State {
public:

	int now;
	int money;
	int damaged;

	State(int now, int money, int damaged) {
		this->now = now;
		this->money = money;
		this->damaged = damaged;
	}

};

const int INF  = 999999;

vector<Edge> G[101];

int d[101][101];

int N, M, L;

int toV(int n, int l) {
	return n * L + l;
}

int main() {
	while (cin >> N >> M >> L, N + M + L != 0) {
		queue<State> q;
		for (int i = 0; i < 101; i++) {
			G[i].clear();
			for (int j = 0; j < 101; j++) {
				d[i][j] = INF;
			}
		}
		for (int i = 0; i < M; i++) {
			int A, B, D, E;
			cin >> A >> B >> D >> E;
			Edge e { B, D, E };
			Edge e2 { A, D, E };
			G[A].push_back(e);
			G[B].push_back(e2);
		}
		q.push(State(1, L, 0));
		while (!q.empty()){
			State s = q.front();
			q.pop();
			if (s.damaged >= d[s.now][s.money]) continue;
			d[s.now][s.money] = s.damaged;
			
			for (Edge e : G[s.now])
			{
				q.push(State(e.to, s.money, s.damaged + e.E));
				if (s.money - e.D >= 0) {
					q.push(State(e.to, s.money - e.D, s.damaged));
				}
			}
		}
		int m = INF;
		for (int i = 0; i <= L; i++) {
			m = min(m, d[N][i]);
		}
		cout << m << endl;
	}
	return 0;
}