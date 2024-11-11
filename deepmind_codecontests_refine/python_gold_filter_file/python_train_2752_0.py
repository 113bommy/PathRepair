n=int(input())
a=list(map(int,input().split()))
c=0
p=0
for i in range(n):
    if(a[i]>0):
        p+=a[i]
    elif(a[i]==-1 and p==0):
        c+=1
    elif(a[i]==-1 and p!=0):
        p-=1
print(c)