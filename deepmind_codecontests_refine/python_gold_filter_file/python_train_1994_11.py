n=int(input());a=sorted(list(map(int,input().split())));mat=[]
if len(set(a))==1:print(0)
else:
    for i in range(1,n):
        if a[i]!=a[0]:
            p=abs(a[i]-a[0])
            if p%2==0:mat.append([p//2,p])
            else:mat.append([p])
    ans=mat[0]
    for i in range(1,len(mat)):
        s=set(mat[i])
        ans=list(s.intersection(ans))
    if len(ans)>=1:print(ans[0])
    else:print(-1)