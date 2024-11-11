n,k=map(int,input().split())
l=list(map(int,input().split()))
t=sum(l[:k])
pas=[]
pas.append(t)
c=0
old=l[c]
for i in range(k,n):
    t-=old
    c+=1
    old=l[c]
    t+=l[i]
    pas.append(t)
pas2=[]
best=-99**9
kor=-1
for i in range(len(pas)-1,-1,-1):
    if pas[i] >= best:
        best=pas[i]
        kor=i
    pas2.append((best,kor))
res=0
p=n-(res+k)-1-(k-1)
res2=p
best=pas[res]+pas2[res2][0]
ans=[res,res2]
for i in range(1,len(pas)):
    res=i
    p=n-(res+k)-1-(k-1)
    res2=p
    if i+k < len(pas):
        cc=pas[res]+pas2[res2][0]
        if cc > best:
            best=cc
            ans=[res,res2]
    else:
        break
print(ans[0]+1,pas2[ans[1]][1]+1)