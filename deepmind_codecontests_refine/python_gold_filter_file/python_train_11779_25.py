l=[int(x) for x in input().split()]
n=[int(x) for x in input().split()]
c=0
if(l[0]<=n[0]):
    c+=1 
    n[0]=n[0]-l[0]
su=sum(n)
if(l[1]<=n[0]+n[1]):
    su=su-l[1]
    c+=1
if(su>=l[2]):
    c+=1
if(c==3):
    print("YES")
else:
    print("NO")