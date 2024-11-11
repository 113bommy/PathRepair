#import<cstdio>
int t[]={,1,2,3,5,7,8,9,};void s(int n){if(n>7)s(n/8);printf("%d",t[n%8]);}main(){for(int a;scanf("%d",&a),a;puts(""))s(a);}