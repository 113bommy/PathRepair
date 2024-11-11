n,v=map(int,input().split())
l1=[]
c=0
for i in range(n):
    l=list(map(int,input().split()))
    for j in l[1:]:
        if(v>j):
            c+=1
            l1.append(i+1)
            break
print(c)
if(len(l1)>0):
    l1.sort()
    print(*l1)
    
