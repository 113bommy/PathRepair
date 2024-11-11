n,k=map(int,input().split())
l=[int(s) for s in input().split()]
c=0
for i in l:
    k1=str(i)
    m=k1.count('4')+k1.count('7')
    if m<=k:
        c+=1
print(c)