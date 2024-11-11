#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int ans = INF;
char s[100010];

int main() {
    scanf("%s", s);
    for (int i = 1; i < strlen(s); ++i) {
    	if (s[i] != s[i - 1]) ans = min(ans, max(i, (int)(strlen(s) - i))); 
    }
    printf("%d\n", min(ans, (int)(strlen(s))));
    return 0;
}