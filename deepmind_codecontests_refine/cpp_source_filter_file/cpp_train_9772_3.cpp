#include <cstdio>
#include <cstring>

char S[1024];
int  D[256];
int main() {
    scanf("%s", S);
    memset(D, 0, sizeof D);
    for (int i = 0; S[i]; i++)
        D[S[i]] = 1;
    if (D['W'] != D['E'] || D['N'] != D['S'])
        printf("No\n");
    else 
        printf("Yes\n");
    return 0;
}
[z