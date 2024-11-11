a=[]
for i in range(0,32):
    for j in range(0,32):
        a.append((pow(2,i))*(pow(3,j)))
a=sorted(a)
c=0
l,r=map(int,input().split())
for i in range(len(a)):
    if(a[i]>=l and a[i]<=r):
        c+=1
print(c)
    
    
