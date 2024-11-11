l,r=map(int,input().split())
res=0
for it in range(62,-1,-1):
    if ((l>>it)&1) != ((r>>it)&1):
        res=(1<<it+1)-1
        break
print (res)
