#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef __int64 LONG;

LONG zip[3][200];
int M[3];

int a[50][6];
int N, K;

int O[200][200][200];

int main()
{
	scanf("%d %d", &N, &K);	
	memset(zip, -1, sizeof(zip));
	memset(M, 0, sizeof(M));
	memset(a, 0, sizeof(a));
	memset(O, 0, sizeof(O));
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 6; j++){
			scanf("%d", &a[i][j]);
			
			bool f = true;
			for (int k = 0; k < M[j % 3]; k++){
				if (zip[j % 3][k] == a[i][j]){
					f = false;
					break;
				}
			}
			
			if (f){
				zip[j % 3][M[j % 3]] = a[i][j];
				M[j % 3]++;
			}
		}
	}
	
	for (int i = 0; i < 3; i++){
		sort(zip[i], zip[i] + M[i]);
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 6; j++){
			int l = 0;
			int r = M[j % 3] - 1;
			int m = (l + r) / 2;
			
			while (zip[j % 3][m] != a[i][j]){
				if (zip[j % 3][m] < a[i][j]){
					l = m + 1;
				}
				else {
					r = m - 1;
				}
				
				m = (l + r) / 2;
			}
			
			a[i][j] = m;
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int x = a[i][0]; x < a[i][3]; x++){
			for (int y = a[i][1]; y < a[i][4]; y++){
				for (int z = a[i][2]; z < a[i][5]; z++){
					O[x][y][z]++;
				}
			}
		}
	}

	LONG sum = 0;
	
	for (int x = 0; x < 200; x++){
		for (int y = 0; y < 200; y++){
			for (int z = 0; z < 200; z++){
				if (O[x][y][z] >= K){
					sum += (zip[0][x + 1] - zip[0][x]) * 
					       (zip[1][y + 1] - zip[1][y]) *
					       (zip[2][z + 1] - zip[2][z]);
				}
			}
		}
	}
	
	printf("%I64d\n", sum);
	
	return 0;
}