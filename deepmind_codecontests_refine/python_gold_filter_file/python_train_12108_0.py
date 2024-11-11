import sys
input = sys.stdin.readline

N=32
E=[]

for i in range(31,11,-1):
    for j in range(i+1,33):
        E.append((i,j,2**(31-i)))
    
L,R=map(int,input().split())
LX=L
for i in range(22):
    if L+(1<<i)-1<=R:
        E.append((1,32-i,L))
        #print((1,32-i,L))
        LX=L+(1<<i)
    else:
        break

E.append((1,2,1))
L=LX
now=L
X=R-L+1
while X:
    for i in range(30):
        if (1<<i)>X:
            break
    i-=1
    E.append((2,32-i-1,now-1-(1<<i)))
    #print(((2,32-i-1,now-1-(1<<i))))

    now+=(1<<i)
    X-=(1<<i)

print("YES")
print(32,len(E))
for x,y,z in E:
    print(x,y,z)
