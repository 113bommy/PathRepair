#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N, M;

int main() {
	long long  goal = 1000000;

	for (; cin >> N;) {
		if (!N) break;
		long long  v[4000];
		queue<int> que;
		memset(v, 0, sizeof(v));
		for (int i = 0; i < N; i++) {
			long long  e, p, q;
			cin >> e >> p >> q;
			que.push(e-1);
			v[e - 1] += p*q;
		}
		bool flag = false;
		while(!que.empty()){
			if (v[que.front()] >= goal) {
				flag = true;
				v[que.front()] = 0;
				cout << que.front() + 1 << endl;
			}
			que.pop();
		}
		if (!flag) cout << "NA" << endl;
	}

	return 0;
}