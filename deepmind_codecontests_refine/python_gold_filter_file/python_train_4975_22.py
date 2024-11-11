n=int(input())
ki=[[] for _ in range(n)]

for _ in range(n-1):
    a,b=map(int,input().split())
    a,b=a-1,b-1
    ki[a].append(b)
    ki[b].append(a)

odd=[-1]*n
odd[0]=0
todo=[0]
while todo:
    v=todo.pop()
    for nv in ki[v]:
        if odd[nv]==-1:
            odd[nv]=abs(odd[v]-1)
            todo.append(nv)
from collections import Counter
co=Counter(odd)
ans=[0]*n
if co[1]<=n//3:
    cnt1=1
    cnt2=0
    cnt3=1
    for i in range(n):
        if odd[i]==1 and 3*cnt3<=n:
            ans[i]=3*cnt3
            cnt3+=1
        else:
            if cnt1%3==0:cnt1+=1
            if cnt1<=n:
                ans[i]=cnt1
                cnt1+=1
            else:
                ans[i]=n-n%3-cnt2*3
                cnt2+=1

elif co[0]<=n//3:
    cnt1=1
    cnt2=0
    cnt3=1
    for i in range(n):
        if odd[i]==0 and 3*cnt3<=n:
            ans[i]=3*cnt3
            cnt3+=1
        else:
            if cnt1%3==0:cnt1+=1
            if cnt1<=n:
                ans[i]=cnt1
                cnt1+=1
            else:
                ans[i]=n-n%3-cnt2*3
                cnt2+=1
else:
    cnt1=1
    cnt2=1
    cnt3=1
    for i in range(n):
        if odd[i]==1:
            if 3*cnt1-2<=n:
                ans[i]=3*cnt1-2
                cnt1+=1
            else:
                ans[i]=3*cnt3
                cnt3+=1
        else:
            if 3*cnt2-1<=n:
                ans[i]=3*cnt2-1
                cnt2+=1
            else:
                ans[i]=3*cnt3
                cnt3+=1
print(*ans,sep=' ')

