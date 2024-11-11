#include <cstdio>
int main(){
	int i;
	double w,t;

	while( ~scanf("%d,%lf,%lf", &i , &w , &t ) ){
		if( w/t/t >= 25.0 )
			printf("%d\n", i );
	}
}