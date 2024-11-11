n=int(input())
l=list(input())
e=0
l1=l[n:]
l1.sort()

l=l[:n]
l.sort()

if(l[0]<l1[0]):
    for i in range(n):
        if(l[i]>=l1[i]):
            print('NO')
            e=1
        if(e==1):
            break
elif(l[0]>l1[0]):
    for i in range(n):
        if(l[i]<=l1[i]):
            print('NO')
            e=1
        if(e==1):
            break
   
    
else:
    print('NO')
    e=1
if(e==0):
    print('YES')