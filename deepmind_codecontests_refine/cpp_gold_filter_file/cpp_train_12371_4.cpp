#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <algorithm> 
#include <cmath> 

using namespace std; 

#define N 100010
#define M 65540

int n, s[N], x, ans, u, v, w; 
int f[M], inf, sum[20]; 

int dfs(int S) {
    if(!S)return 0; 
    if(f[S] < inf) return f[S]; 
    for(int i = 0; i < 16; i++) {
        if ((S >> i) & 1) {
            for(int j = 0; j < 16; j++) {
                if (i != j && (S >> j) & 1) {
                    int p = i^j, x = S^(1 << i)^(1 << j)^(1 << p); 
                    if (S >> p & 1)f[S] = min(f[S], dfs(x) + 2); 
                    else f[S] = min(f[S], dfs(x) + 1); 
                }
            }
        }
    }   
    return f[S]; 
}

int main() {
    scanf("%d",&n); 
    for(int i = 1 ; i < n ; i++) {
        scanf("%d%d%d",  & u,  & v,  & w); 
        s[u] ^= w, s[v] ^= w; 
    }
    for(int i = 0 ; i < n ; i++) sum[s[i]]++; 
    for(int i = 1 ; i < 16 ; i++) {
        ans += (sum[i] >> 1); 
        x += (1 << i) * (sum[i] & 1); 
    }
    memset(f, 127, sizeof(f)); 
    inf = f[0]; 
    printf("%d\n", ans + dfs(x)); 
    //system("pause");
    return 0; 
}