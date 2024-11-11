n=int(input())
a=list(map(int,input().split()))
s=0
c=0
b=[]
for i in range(len(a)):
    if(a[i]%2!=0):
        c+=1 
        b.append(a[i])
    else:
        s=s+a[i]
b.sort()
if(c%2==0):
    for i in range(len(b)):
        s=s+b[i]
else:
    for i in range(1,len(b)):
        s=s+b[i]
print(s)      