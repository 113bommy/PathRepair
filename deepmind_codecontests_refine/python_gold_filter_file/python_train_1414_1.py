k,a,b = list(map(int,input().split()))
if a < b:
    a,b = b,a
if a>=k and b<k:
    if a % k == 0:
        print(a//k)
    else:
        print(-1)
elif a>=k and b>=k:
    print(a//k+b//k)
else:
    print(-1)
     