from collections import Counter
nrew = int(input())
for wew in range(nrew):
    a,b,n = list(map(int,input().split(" ")))
    if(a>n or b>n):
        print(0)
        continue
    m = max(a,b)
    a += b  
    b = m  
    ans = 1
    while a<=n and b<=n:
        b+=a
        ans+=1
        temp = a
        a = b
        b = temp
    print(ans)