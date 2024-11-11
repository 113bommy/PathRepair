#include <cstdio>
int main(){
	int n,h,m;
	scanf("%d",&n);
	for(;n--;){
		scanf("%d:%d",&h,&m);
		double s=h*30+m/2.,l=m*6,t,d;
		l<s?t=l,l=s,s=t:0;
		d=s-l+360;
		l-s<d?d=l-s:0;
		d<30?
			puts("alert")
		:
			d<90?
				puts("warning")
			:
				puts("safe");
	}
}