n=int(input())
l1=list(map(int,input().strip().split()))
l2=sorted(l1)
d=[]
for i in range(n):
    if l1[i]!=l2[i]:
        a=l1.index(l2[i],i)
        d.append([a,i])
        l1[i],l1[a]=l1[a],l1[i]
print(len(d))
for i in d:
    print(*i)
        
        