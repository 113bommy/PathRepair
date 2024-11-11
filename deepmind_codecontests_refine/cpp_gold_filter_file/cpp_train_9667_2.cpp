#include <stdio.h>

int main(){
	int h, w, i, j, ct=0;
	char c;
	scanf("%d%d\n",&h,&w);
	for( i=0; i<h; i++ ){
		for( j=0; j<w; j++ ){
			scanf("%c",&c);
			if( c=='#' ) ct++;
		}
		getchar();
	}
	if( ct == w+h-1 ) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}