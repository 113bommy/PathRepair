t = int(input())
mod = 1000000007
    
def solve():
    n, k = map(int, input().split())
    res = 0
    for i in range(0, 32):
        if (k >> i) & 1:
            res = res % mod + ((n % mod)**(i % mod)) % mod
    print(res % mod)
 
for i in range(1, t + 1):
    solve()