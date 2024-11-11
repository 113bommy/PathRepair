n=int(input())
d=dict()
for i in range(n):
    s=input()
    if s in d:
        d[s]+=1
    else:
        d[s]=1
ans=[0]
maxg = float("-inf")
for i,j in d.items():
    if j > maxg:
        maxg=j
        ans[0]=i
print(ans[0])