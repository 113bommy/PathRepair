x,y,z,k=map(int,input().split())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
c=[int(i) for i in input().split()]


ab=[]

for i in a:
    for j in b:
        ab.append(i+j)
ab.sort()
ab.reverse()
ans=[]
for i in range(min(k,len(ab))):
    for j in c:
        ans.append(ab[i]+j)
ans.sort()
ans.reverse()

for i in range(k):
    print(ans[i])

