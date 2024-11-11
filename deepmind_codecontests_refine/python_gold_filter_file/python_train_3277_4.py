x=input()
m=int(input())
a1=[int(i)-1 for i in input().split()]
ll=len(x)
ll+=ll%2
u=(ll//2)*[0]
for i in range(m):
    u[a1[i]]+=1
for i in range(1,ll//2):
    u[i]=u[i]+u[i-1]
p1=''
p2=''
#print(u)
for i in range(len(x)//2):
    if u[i]%2==0:
        p1+=x[i]
        p2=x[-i-1]+p2
        
    else:
        p2=x[i]+p2
        p1+=x[-i-1]
    #print(p1,p2)
if len(x)%2==1:
    print(p1+x[len(x)//2]+p2)
else:
    print(p1+p2)
    
