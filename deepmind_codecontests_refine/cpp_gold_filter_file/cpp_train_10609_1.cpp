#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, Q;

	while (cin >> N >> Q, N && Q) {
		int avail[100] = {};

		for (int i = 0; i < N; i++) {
			int M; cin >> M;
			for (int j = 0; j < M; j++) {
				int tmp; cin >> tmp;
				avail[tmp-1] += 1;
			}
		}

		int max = 0;
		int idx = -1;
		for (int i = 0; i < 100; i++) {
			if (avail[i] >= Q && max < avail[i]) {
				idx = i;
				max = avail[i];
			}
		}

		cout << (idx == -1 ? 0 : idx+1) << endl;
	}

	return 0;
}