h,w,n=map(int,input().split())
D=dict()
for i in range(n):
    a,b=map(int,input().split())
    for p in range(-1,2):
        for q in range(-1,2):
            aa=a+p
            bb=b+q
            if 2<=aa<=h-1 and 2<=bb<=w-1:
                aabb=str(aa)+"_"+str(bb)
                if aabb in D:
                    D[aabb]+=1
                else:
                    D[aabb]=1
ans=[0]*10
V=list(D.values())
for v in V:
    ans[v]+=1
ans[0]=(h-2)*(w-2)-sum(ans)
for i in range(10):
    print(ans[i])