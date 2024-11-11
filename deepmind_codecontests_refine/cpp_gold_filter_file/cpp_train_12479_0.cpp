#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<complex>
using namespace std;

typedef complex<double> P;

#define X real()
#define Y imag()
int d[4];
bool f=0;
const char *op="+-*";

int cal(int a,int o,int b){
    if(o==0) return a+b;
    if(o==1) return a-b;
    return a*b;
}

bool sol(int a,int b,int c) {
    f++;
    if (cal(cal(cal(d[0],a,d[1]),b,d[2]),c,d[3])==10) {
        printf("(((%d %c %d) %c %d) %c %d)\n",d[0],op[a],d[1],op[b],d[2],op[c],d[3]);
        return true;
    }
    if (cal(cal(d[0],a,d[1]),b, cal(d[2],c,d[3]))==10) {
        printf("((%d %c %d) %c (%d %c %d))\n",d[0],op[a],d[1],op[b],d[2],op[c],d[3]);
        return true;
    }
    if (cal(cal(d[0],a, cal(d[1],b,d[2])),c,d[3])==10) {
        printf("((%d %c (%d %c %d)) %c %d)\n",d[0],op[a],d[1],op[b],d[2],op[c],d[3]);
        return true;
    }
    return f=0;
}

bool jg() {
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            for (int k=0;k<3;++k) {
                if (sol(i,j,k)) return true;
            }
        }
    }
}


int main(){
    int mod=1000000007;
    for (;;) {
        scanf("%d %d %d %d",&d[0],&d[1],&d[2],&d[3]);
        if (d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && d[0]==0) break;
        sort(d,d+4);
        do {
            if (jg()) break;
        } while (next_permutation(d,d+4));
        if (f==0) printf("0\n");
    }
    return 0;
}