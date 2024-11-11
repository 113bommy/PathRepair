def make(l,n):
    if n<3:
        return l
    z=[0 for _ in range(n)]
    l.sort()
    z[-1]=l[-1]
    z[0]=l[-2]
    z[-2]=l[-3]
    l.pop()
    l.pop()
    l.pop()
    i,j=1,n-3
    while i<j:
        z[i]=l.pop()
        i+=1
        z[j]=l.pop()
        j-=1
    if i==j:
        z[i]=l.pop()
    return z
n=int(input())
l=list(map(int,input().strip().split()))
print(" ".join(str(x) for x in make(l,n))) 
