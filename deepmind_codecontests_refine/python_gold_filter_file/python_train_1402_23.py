inp=input().split()
n=int(inp[0])
k=int(inp[1])
l=[]
def gcd(a,b):
    if(b==0):
        return a
    return gcd(b,a%b)
flag=False
for i in range(n,k+1):
    for j in range(i+1,k+1):
        for k in range(j+1,k+1):
            
            if(gcd(i,j)==1 and gcd(j,k)==1 and gcd(i,k)!=1 and i!=j and j!=k and i!=k):
                l.append(i)
                l.append(j)
                l.append(k)
                flag=True
                break
        if(flag):
            break
    if(flag):
        break
                
if(len(l)==0):
    l.append(-1)
for i in range(len(l)):
    print(l[i],end=' ')
        