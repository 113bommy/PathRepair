import math
for _ in range(int(input())):
    n,k = map(int, input().split())
    mod = 1000000007
    num = 0
    while k>0:
        x = int(math.log(k,2))
        x %= mod
        c = (n**x)%mod
        
        num +=c
        k -= 2**x
        
    print(num%mod)