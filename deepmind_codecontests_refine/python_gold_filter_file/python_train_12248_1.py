n,a,b=map(int,input().split())
cop=n
if a>b:
    a,b=b,a
j=-1
ke=-1
while(n>=0):
    if n%a==0:
        j=n//a
        ke=(cop-a*j)//b
        #print(j,ke)
        break
    else:
        n-=b
#print(n,j,ke)
if j==-1:
    print(-1)
else:
    ans=[]
    t=1
    for yu in range(j):
       for ty in range(a):
           k=t+(ty+1)%a
           if k==0:
               k+=a
           ans.append(k)
       t+=a 
       #print(t)
    for yu in range(ke):
       for ty in range(b):
           k=t+(ty+1)%b
           if k==0:
               k+=b
           ans.append(k)
       t+=b 
    print(*ans,sep=" ")
    
        