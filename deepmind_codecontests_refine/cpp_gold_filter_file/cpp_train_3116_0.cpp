#include <cmath>
#include <cstdio>
#include <cstring>
#include <bitset>
#define maxn 500300
using namespace std;

bitset<1000000006> S;

int n;
int a[maxn];




char s[10000];

inline void read(int &x) {
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}

bool full=0;
int tot=0;
int pre=1;

int T=0;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        //scanf("%d",&x);
        read(a[i]);
        int x=a[i];
        if (full)
            {
                puts("No");
                continue;
            }
        if (a[i]<pre)
            {
                puts("No");
                continue;
            }
        while (S.test(a[i]))
            {
                a[i]--;
                if (a[i]==0)
                    break;
            }
        if (a[i]==0)
            if (tot==x)
                {
                    puts("Yes");
                    full=1;
                }
            else
                puts("No");
        else
            {
                while (x!=a[i])
                    {
                        S.set(x,0);
                        tot--;
                        if (tot<0)
                            return 0;
                        x--;
                    }
                tot++;
                while (S.test(pre))pre++;
                S.set(a[i],1);
                puts("Yes");
            }
    }
	return 0;
}