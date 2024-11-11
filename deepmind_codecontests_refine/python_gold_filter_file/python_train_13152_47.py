n,a,b,c = map(int,input().split())
d=[0]+[-1e9]*5000
for i in range(1,n+1):
    d[i]=max(d[i-a],d[i-b],d[i-c])+1
print(d[n])