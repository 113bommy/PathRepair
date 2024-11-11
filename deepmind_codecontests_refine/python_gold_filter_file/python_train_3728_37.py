x,y,z,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
e=[]
for ai in a:
    for bi in b:
        e.append(ai+bi)
e.sort(reverse=True)
e=e[:k]
ans=[]
for ci in c:
    for ei in e:
        ans.append(ci+ei)
ans.sort(reverse=True)
for i in range(k):
    print(ans[i])