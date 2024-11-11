n=int(input())
a=input().split()
b=[]
for i in range(n):
    a[i]=int(a[i])
    b.append([a[i],i])

b.sort(reverse = True)
ans=0
c=[]
for i in range(n):
    ans+=i*b[i][0]+1
    c.append(b[i][1])    
print(ans)   
for i in range(n):
    print(c[i]+1,end=" ")