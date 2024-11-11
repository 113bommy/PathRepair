#import<cstdio>
int n,h,a,p;
int main(){scanf("%d",&n);while(n--){scanf("%d",&h);if(h>p)a+=h-p;p=h;}printf("%d",a);}
