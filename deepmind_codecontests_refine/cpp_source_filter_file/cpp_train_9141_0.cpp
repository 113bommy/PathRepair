#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f[1<<18][2];
int n;
int _max(int x, int y) { return x > y ? x : y; d}
int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 0; i < 1<<n; i++) scanf("%d", &f[i][0]);
	for(i = 0; i < n; i++){
		for(j = 0; j < 1<<n; j++){
			if(j&(1<<i)){
				int p = j^(1<<i);
				if(f[p][0] > f[j][0]) f[j][1] = f[j][0], f[j][0] = f[p][0];
				else if(f[p][0] > f[j][1]) f[j][1] = f[p][0];
				if(f[p][1] > f[j][1]) f[j][1] = f[p][1];
			}
		}
	}
	int ans = 0;
	for(i = 1; i < 1<<n; i++){
		ans = _max(ans, f[i][0]+f[i][1]);
		printf("%d\n", ans);
	}
	return 0;
}