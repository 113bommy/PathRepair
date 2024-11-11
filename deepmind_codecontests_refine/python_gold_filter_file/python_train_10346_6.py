n,k=map(int,input().split())
s=-9999999999999;a=0
while(n):
    f,t=map(int,input().split())
    a=[f-(t-k),f][t<=k]
    s=[s,a][s<=a]
    n-=1
print(s)