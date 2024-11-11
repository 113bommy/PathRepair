#import<cstdio> int n,h,a,p;
main(){scanf("%d",&n);while(n--){scanf("%d",&h);if(h>p)a+=h-p;p=h;}printf("%d",a);}
