#include<cstdio>
int n;
int a[105];
int myabs(int x) {
if(x>0) return x;
return -x;
}
int main() {
	int avg = 0;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		avg += a[i];
		a[i] *= n;
	}
	int min = 2147483647,w=-1;
	for (i = 0; i < n; i++) {
		if (abs(avg - a[i]) < min) {
			min = myabs(avg - a[i]);
			w = i;
		}
	}
	printf("%d", w);
	return 0;
}