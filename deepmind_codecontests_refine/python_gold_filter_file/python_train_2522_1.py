import math
n,m,k=[int(x) for x in input().split()]
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a_one=[]
b_one=[]
i=t=0

while i < n:
    if a[i] == 1:
        t+=1
    else:
        a_one.append(t)
        t=0
    i+=1
a_one.append(t)
i=t=0
while i < m:
    if b[i] == 1:
        t+=1
    else:
        b_one.append(t)
        t=0
    i+=1
b_one.append(t)

def solve(r,c,a_one,b_one):
    p=q=i=0
    while i < len(a_one):
        p+=max(a_one[i]-(r-1),0)
        i+=1
    i=0
    while i<len(b_one):
        q+=max(b_one[i]-(c-1),0)
        i+=1
    return (p*q)
ans=0
for i in range(1,(int(math.sqrt(k))+1)):
    if k%i == 0:
        c=k//i
        #print(c)
        ans+= solve(i,c,a_one,b_one)
        if i != c:
            ans+= solve(c,i,a_one,b_one)
print(ans)


