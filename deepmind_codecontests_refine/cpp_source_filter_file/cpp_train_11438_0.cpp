#include <bits/stdc++.h>
#define ll long long
#define uint unsignextd long long
#define db double
#define ls x << 1
#define rs x << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 500010 , mod = 1e9 + 7;
int n, next[N], next2[N];
char s[N];
bool is(int x, int *next)
{
    return next[x] && x % (x - next[x]) == 0;
}
 
int main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    int j = 0;
    rep(i, 2, n)
    {
        while(j && s[j + 1] != s[i]) j = next[j];
        next[i] = s[j + 1] == s[i] ? ++ j : j;
    }
    if(!is(n, next)) printf("1\n1\n");
    else if(next[n] == n - 1) printf("%d\n1\n",n);
    else
    {
        reverse(s + 1, s + 1 + n);
        j = 0;
        rep(i, 2, n)
	    {
	        while(j && s[j + 1] != s[i]) j = next2[j];
	        next2[i] = (s[j + 1] == s[i] ? ++ j : j);
	    }
        int ans = 0;
        rep(i, 1, n - 1) 
        	if(!is(i, next) && !is(n - i, next2)) ans ++;
        printf("2\n%d\n", ans);
    }
    return 0;
}
