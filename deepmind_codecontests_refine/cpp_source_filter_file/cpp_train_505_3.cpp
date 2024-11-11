#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100
#define MMAX 5001
int X, Y, Z, A[MAX], V[MAX], E[MAX];
void compute() {
	float P[MMAX][MAX];
	for (int i = 0; i < MMAX; i++) {
		for (int j = 0; j <= Y; j++)
			P[i][j] = 0;
	}
	P[0][0] = 1.0;
	int np, nv;
	for (int j = 0; j < Y; j++) {
		for (int i = 0; i < MMAX; i++) {
			if (P[i][j] == 0)
				continue;
			for (int k = 0; k < X; k++) {
				np = min(Y, j + V[k]);
				nv = i;
				if (E[np] == 1) {
					np = min(Y, np + A[np]);
				} else if (E[np] == 2) {
					nv = i + A[np];
				} else if (E[np] == 3) {
					nv = max(0, i - A[np]);
				}
				P[nv][np] += P[i][j] * (1.0 / X);
			}
		}
	}
	double ex = 0;
	for (int i = 0; i < MMAX; i++)
		ex += P[i][Y] * i;
	cout << (int) ex << endl;
}
void main() {
	int n, e, a;
	while(1) {
		cin >> X >> Y >> Z;
		if ( X == 0 && Y == 0 && Z == 0 ) break;
		for ( int i = 0; i <= Y; i++ ) A[i] = E[i] = 0;
		for ( int i = 0; i < X; i++ ) cin >> V[i];
		for ( int i = 0; i < Z; i++ ) {
			cin >> n >> e >> a;
			A[n] = a;
			E[n] = e;
		}
		compute();
	}
	return 0;
}