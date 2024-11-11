n,h=input().split(' ')
n=int(n)
h=int(h)
 
a=input().split(' ')
for i in range(len(a)):
    a[i]=int(a[i])
    
ans=0
for i in a:
    if i>h:
        ans+=1
    ans+=1
print(ans)