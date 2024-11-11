n=int(input())
a=input().strip()
b=input().strip()
from collections import defaultdict 
da,db=defaultdict(list),defaultdict(list)
qa=[]
qb=[]
for i in range(n):
    if a[i]=='?':
        qa.append(i)
    else:
        da[a[i]].append(i)
    if b[i]=='?':
        qb.append(i)
    else:
        db[b[i]].append(i)
ans=[]
for c in "abcdefghijklmnopqrstuvwxyz":
    u,v=da[c],db[c]
    while u and v:
        ans.append([u.pop(),v.pop()])
    while u and qb:
        ans.append([u.pop(),qb.pop()])
    while v and qa:
        ans.append([qa.pop(),v.pop()])
while qa and qb:
    ans.append([qa.pop(),qb.pop()])
print(len(ans))
for i in range(len(ans)):
    print(ans[i][0]+1,ans[i][1]+1)