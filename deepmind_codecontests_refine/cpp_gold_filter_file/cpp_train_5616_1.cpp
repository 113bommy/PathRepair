#import<cstdio>
#import<map>
#define I(M,A)for(i=0;i<M;i++)scanf("%d",&x),A[i+1]=A[i]+x;
int main(){for(int n[1501],m[1501],o,a,b,i,j,x;scanf("%d%d",&a,&b),a;printf("%d\n",o)){std::map<int,int>z;*n=*m=o=0;I(a,n)I(b,m)for(i=0;i<=a;i++)for(j=0;j<=b;j++)z[n[i]+m[j]]++;for(std::map<int,int>::iterator p=z.begin();p!=z.end();p++)o+=(p->second)*((p->second)-1)/2;}}