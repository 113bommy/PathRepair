#include <algorithm>
#include <cstdio>
#include <cstring>

#define int long long
#define Accepted 0; 

const int Maxv = 100010; 
int d[Maxv], d1[Maxv], u[Maxv], ghostfly233[Maxv], siz[Maxv], cnt, n;  

inline int GldHkkowoSearch(int x) {
     tmp = std::lower_bound(d + 1, d + n + 1, x) - d;

    if (d[tmp] != x) {
        puts("-1"); 
        exit(0); 
    }

    return tmp; 
}

signed main() {
    scanf("%lld", &n); 
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &d[i]); 
        d1[i] = d[i]; 
    }

    std::sort(d + 1, d + n + 1); 
    for (int i = 1; i <= n; i++) 
        ghostfly233[GldHkkowoSearch(d1[i])] = i;       

    for (int i = 1; i <= n; i++)
        siz[i] = 1; 

    for (int i = n; i > 1; i--) {
        u[i] = GldHkkowoSearch(d[i] - n + (siz[i] << 1)); 
        siz[ u[i] ] += siz[i]; 
        cnt += siz[i]; 
    }

    if (cnt != d[1]) {
        puts("-1"); 
        return 0; 
    }

    for (int i = 2; i <= n; i++)
        printf("%lld %lld\n", ghostfly233[i], ghostfly233[ u[i] ]); 

    return Accepted;  
}