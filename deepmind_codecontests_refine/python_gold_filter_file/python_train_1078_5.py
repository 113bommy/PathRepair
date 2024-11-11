
def mod(a, b, m):
    if(b==1): return a%m
    elif(b%2==0):
        b = b // 2
        x = mod(a, b, m)
        return (x*x)%m
    else:
        b = b - 1
        return ((a%m)*mod(a, b, m))%m

size = int(input())

if(size < 3): print(-1)
else:
    rem = mod(10, size-1, 210)
    ans = pow(10, size-1) + (210-rem)

    print(ans)
