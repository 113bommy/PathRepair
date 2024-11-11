n,m=map(int,input().split())
l=list(map(int,input().split()))
tmp=[0]*n

for i in range(m):
    a,b=map(int,input().split())
    if l[a-1] >= l[b-1]:
        tmp[b-1]=-1
    if l[a-1] <= l[b-1]:
        tmp[a-1]=-1

print(tmp.count(0))