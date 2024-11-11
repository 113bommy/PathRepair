n=int(input())
l=[int(x) for x in input().split()]
c,m=0,-1
for i in range(n-1):
    if l[i+1]<=l[i]:
        if m<=c:
            m=c+1
        c=0
    else:
        c+=1
if m<=c:
    m=c+1
print(m)