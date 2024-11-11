n = int(input())
A = list(map(int,input().split()))

c=[0]*8
maxc=0
for a in A:
    if a>=3200:
        maxc+=1
    else:
        c[a//400]=1
minc = c.count(1)
ans = minc+maxc
print(max(minc,1),ans)
