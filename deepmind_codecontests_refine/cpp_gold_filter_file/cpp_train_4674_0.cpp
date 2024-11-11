#include <cstdio>
int P[100000],T[100000];
int main() {
    int N,R,L,PT=0,n1=0;
    scanf("%d %d %d",&N,&R,&L);
    for(int i=0;i<R;i++) {
        int d,t,x;
        scanf("%d %d %d",&d,&t,&x); d--;
        P[d]+=x;
        if(x>0) {
            if(P[d]>P[n1]||(P[d]==P[n1]&&n1>d)) {
                T[n1]+=t-PT+1;
                PT=t;
                n1=d;
            }
        }
        if(x<0) {
            if(d!=n1) continue;
            int n2=n1,p2=P[d];
            for(int j=N-1;j>=0;j--) {
                if(p2<=P[j]) {n2=j,p2=P[j];}
            }
            if(n2!=n1) {
                T[n1]+=t-PT+1;
                PT=t;
                n1=n2;
            }
        }
    }
    T[n1]+=L-PT+1;
    int ans_n=0,ans_t=0;
    for(int i=0;i<N;i++) {
        if(ans_t<T[i]) {
            ans_t=T[i];
            ans_n=i;
        }
    }
    printf("%d\n",ans_n+1);
}