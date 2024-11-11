n=int(input())
s=list(map(int,input().split()))
l=[0 for _ in range(13)]
for x in s:
    l[x//400]+=1
j=sum(r>0 for r in l[:8])
print(max(1,j),j+sum(l[8:]))