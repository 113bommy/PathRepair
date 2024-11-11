#include <bits/stdc++.h>
using namespace std;

char str[1024];
bool f[1024][1024];

int main()
{
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; i++){
		f[i][i] = true;
	}
	for (int t = 0; t < n / 2; t++){
	for (int w1 = 0; w1 < n; w1 += 3){
		for (int w2 = 0; w2 < n; w2 += 3){
			for (int i = 0; i < n; i++){
				int j = i + w1 + 1;
				int k = i + w1 + w2 + 2;
				if (str[i] != 'm') continue;
				if (str[j] != 'e') continue;
				if (str[k] != 'w') continue;
				if (!f[i + 1][j]) continue;
				if (!f[j + 1][k]) continue;
				f[i][k + 1] = true;
			}
		}
	}
	}
	puts(f[0][n] ? "Cat" : "Rabbit");
}