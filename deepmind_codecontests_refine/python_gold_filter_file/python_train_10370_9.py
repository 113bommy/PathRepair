n, k = map(int, input().split())
a = list(map(int, input().split()))
i=1
t=0
while i-1<n:
    t+=a[i-1]
    k-=min([8,t])
    t-=min(8,t)
    if k<=0:
        print(i)
        break
    i+=1
else:
    print(-1)