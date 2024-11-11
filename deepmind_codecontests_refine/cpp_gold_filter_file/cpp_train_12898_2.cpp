#include <stdio.h>
#include <algorithm>

using namespace std;

inline bool check(int n)
{
    int rep = min(n, 40000);
    
    for(int x = 1; x < rep; x++)
    {
        if((n - x) % (2 * x + 1) == 0)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    int n, q, c = 0;
    
    scanf("%d", &q);
    
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &n);
        
        c += check(n) ? 0 : 1;
    }
    
    printf("%d\n", c);
    
    return 0;
}