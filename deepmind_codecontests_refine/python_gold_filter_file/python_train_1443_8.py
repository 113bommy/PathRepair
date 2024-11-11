n=int(input())
a=list(map(int,input().split()))
if n%2==1:
    x=[i for i in range(n)]
    for i in range(n):
        if i%2==1:
            x[i]+=1
else:
    x=[i for i in range(n)]
    for i in range(n):
        if i%2==0:
            x[i]+=1
a.sort()
if x==a:
    print(pow(2,(n//2),10**9+7))
else:
    print(0)