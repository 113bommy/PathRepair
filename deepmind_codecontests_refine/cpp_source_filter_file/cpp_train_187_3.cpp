#include <iostream>
using namespace std;
 
int main() {
	int F[100][10], P[100][11], p[100] = { 0 }, N;
	long long int sum = 0, max = 0;
 
	cin >> N;
	for (int i = 0; i<N; i++)for (int j = 0; j<10; j++) cin >> F[i][j];
	for (int i = 0; i<N; i++)for (int j = 0; j<11; j++) cin >> P[i][j];
 
	for (int i = 1; i<1024; i++) {
		for (int j = 0; j<N; j++)p[j] = q[j] = 0;
		for (int j = 0; j<11; j++)
			if ((i>>j)%2)
				for (int k = 0; k<N; k++)p[k] += F[k][j];
		sum = 0;
		for (int j = 0; j < N; j++) sum += P[j][p[j]];
		if (i == 1 || sum > max)max = sum;
	}
	cout << max << endl;
	return 0;
}