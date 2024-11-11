n=int(input())
l=list(map(int, input().split()))
for i in range(1,n+1):
    l[0:i]=sorted(l[0:i])
    print(*l)