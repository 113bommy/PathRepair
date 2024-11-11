import math,sys

n,p=map(int,sys.stdin.readline().split())
limit = int(p ** (1/n))+1
if limit==1:
    print(1)
elif n==1:
    print(p)
else:
    cnt,ans=0,1

    while p % 2 == 0:
        p /= 2
        cnt += 1
    ans *= 2 ** (cnt // n)
    
    for div in range(3, limit, 2):
        cnt = 0
        while p % div == 0:
            cnt += 1
            p /= div
        if cnt >= n:
            ans *= div ** (cnt // n)
    print(ans)