#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 305;
int A, B, D[15][15], F[105][105];
int S, T, M;
int main()
{
	scanf("%d%d", &A, &B);
	for(int I = 1; I <= A; ++I)
		for(int J = 1; J <= B; ++J)
			scanf("%d", &D[I][J]);
	for(int numX = 0; numX <= 100; ++numX)
		for(int numY = 0; numY <= 100 && numX + numY <= 100; ++numY){
			for(int X = 1; X <= A; ++X)
				for(int Y = 1; Y <= B; ++Y)
					F[numX][numY] = max(F[numX][numY], D[X][Y] - numX * X - numY * Y);
		}
	M = 200 + 101 * 101;
	S = 1, T = 202;
	for(int X = 1; X <= A; ++X)
		for(int Y = 1; Y <= B; ++Y){
			int minDis = 0x3f3f3f3f;
			for(int numX = 0; numX <= 100; ++numX)
				for(int numY = 0; numY <= 100 && numX + numY <= 100; ++numY)
				{
					minDis = min(minDis, X * numX + Y * numY + F[numX][numY]);
				}
			if(minDis != D[X][Y]){
				puts("Impossible");
				return 0;
			}
		}
	puts("Possible");
	cout<<202<<" "<<M<<endl;
	for(int I = 1; I <= 100; ++I)
		printf("%d %d X\n", I, I + 1);
	for(int I = 102; I <= 201; ++I)
		printf("%d %d Y\n", I, I + 1);
	for(int I = 0; I <= 100; ++I)
		for(int J = 0; J <= 100; ++J){
			printf("%d %d %d\n", 1 + I, 102 + J, F[I][100 - J]);
	cout<<S<<" "<<T<<endl;
	return 0;
}
