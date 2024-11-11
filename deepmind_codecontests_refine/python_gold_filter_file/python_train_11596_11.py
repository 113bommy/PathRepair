n,k=map(int,input().split())
l=list(map(int,input().split()))

l.sort()
res=set()
for i in l:
    if i%k==0 and i/k in res:
        pass
    else:
        res.add(i)

print (len(res))