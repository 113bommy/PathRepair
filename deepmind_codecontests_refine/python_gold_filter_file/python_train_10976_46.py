n,m=map(int,input().split())
a=list(map(int,input().split()))
k=0
for i in range(n):
    if a[i]+m<=5:
        k=k+1
print(k//3)