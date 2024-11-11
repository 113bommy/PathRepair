H,W,K=map(int,input().split())
S=[[int(s) for s in input()] for i in range(H)]

ans=1000000
for i in range(2**(H-1)):
    tmp=0
    L=[]
    for j in range(H-1):
        if i>>j&1:
            L.append(j)
    tmp+=len(L)
    L.append(H-1)
    c=[0]*len(L)
    for k in range(W):
        h=0
        c1=[0]*len(L)
        for l in range(len(L)):
            for m in range(h,L[l]+1):
                c1[l]+=S[m][k]
            h=L[l]+1
        p=0
        for l in range(len(L)):
            if c1[l]>K:
                p=2
                break
            elif c[l]+c1[l]>K:
                p=1
            else:
                c[l]+=c1[l]
        if p==2:
            break
        elif p==1:
            c=[i for i in c1]
            tmp+=1
    else:
        ans=min(ans,tmp)
print(ans)