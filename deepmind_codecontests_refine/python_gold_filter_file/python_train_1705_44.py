n,m=map(int,input().split())
minn=min(n,m)
print(minn+1)
for i in range(minn+1):
    print(i,minn-i)