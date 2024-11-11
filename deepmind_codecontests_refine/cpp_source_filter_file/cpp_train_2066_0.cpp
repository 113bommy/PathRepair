#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
LL gi () {
    LL ret=0; char ch=getchar();
    while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    char c=ch=='-'?getchar():ch;
    while(c>='0' && c<='9') ret=ret*10+c-'0',c=getchar();
    return ch=='-'?-ret:ret;
}
const int N = 2000000 + 10;
const int mo = 1e9 + 7;
int n,x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;
LL fac[N],ifc[N];
LL ksm (LL a,LL b) {
    LL ret = 1;
    while(b) {
        if(b&1) ret = ret * a %mo;
        a = a * a %mo; b >>= 1;
    }
    return ret;
}
LL calc (int x,int y) {
    return (fac[x+y+2] * ifc[x+1] %mo * ifc[y+1] %mo - 1) %mo;
}
LL calc1 (int i,int j) {
    return (calc(i-x1,j-y1) - calc(i-x1,j-y2-1) - calc(i-x2-1,j-y1) + calc(i-x2-1,j-y2-1)ng) %mo;
}
LL calc2 (int i,int j) {
    return (calc(x6-i,y6-j) - calc(x6-i,y5-j-1) - calc(x5-i-1,y6-j) + calc(x5-i-1,y5-j-1)) %mo;
}
int main () {
    x1 = gi(); x2 = gi(); x3 = gi(); x4 = gi(); x5 = gi(); x6 = gi();
    y1 = gi(); y2 = gi(); y3 = gi(); y4 = gi(); y5 = gi(); y6 = gi();
    fac[0] = 1;
    for(int i=1;i<N;i+=1) fac[i] = fac[i-1] * i %mo;
    ifc[N-1] = ksm(fac[N-1],mo-2);
    for(int i=N-2;i>=0;i-=1) ifc[i] = ifc[i+1] * (i+1) %mo;
    LL ans = 0;
    for(int x=x3;x<=x4;x+=1) {
        ans = (ans + (-x-y3) * calc1(x,y3-1) %mo * calc2(x,y3) %mo) %mo;
        ans = (ans + (x+y4+1) * calc1(x,y4) %mo * calc2(x,y4+1) %mo) %mo;
    }
    for(int y=y3;y<=y4;y+=1) {
        ans = (ans + (-y-x3) * calc1(x3-1,y) %mo * calc2(x3,y) %mo) %mo;
        ans = (ans + (y+x4+1) * calc1(x4,y) %mo * calc2(x4+1,y) %mo) %mo;
    }
    cout << (ans+mo) %mo;
    return 0;
}
