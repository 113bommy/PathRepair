#include <stdio.h>

int main(){
	int n, cnt = 1;
	scanf("%d", &n);
	while (n){
		float s = 0, x0, y0, xa, xb, ya, yb;
		scanf("%f %f", &x0, &y0);
		xb = x0;
		yb = y0;
		for (int i = n - 1; i>0; i--){
			xa = xb;
			ya = yb;
			scanf("%f %f", &xb, &yb);
			s += (xb + xa)*(yb - ya);
		}
		s += (x0 + xb)*(y0 - yb);
		printf("%d %.1f\n", cnt++, s>0 ? s / 2 : (-s) / 2);
		scanf("%d", &n);
	}
	return 0;
}