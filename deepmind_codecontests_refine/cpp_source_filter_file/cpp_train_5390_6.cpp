Copy
#include <cstdio>

const int MAX = 2e5+10;
char s[MAX];
int n;

int main(){
    scanf("%d%s\n", &n, s);
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'R') cnt++;
    for (int i = 0; i < cnt; i++) if (s[i] == 'W') ans++;
    printf("%d\n", ans);
    return 0;
}