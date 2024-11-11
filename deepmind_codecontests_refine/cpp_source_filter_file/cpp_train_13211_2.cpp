#include <stdio.h>
#include <math>

struct vertex{
	int x;
	int y;
};

double areaTriangle(vertex p1, vertex p2, vertex p3)
{
	double vec1_x = p2.x - p1.x, vec1_y = p2.y - p1.y;
	double vec2_x = p3.x - p1.x, vec2_y = p3.y - p1.y;
	
	return (vec1_x * vec2_y - vec1_y * vec2_x) / 2;
}

int main(void)
{
	int cnt = 0;
	int n;
	vertex p[50];
	
	double area;
	
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		
		for(int i = 0; i < n; i++){
			scanf("%d %d", &p[i].x, &p[i].y);
		}
		
		area = 0;
		for(int i = 1; i+1 < n; i++){
			area += areaTriangle(p[0], p[i], p[i+1]);
		}
		area = fabs(area);
		
		cnt++;
		printf("%d %.1f\n", cnt, area);
	}
	
	return 0;
}