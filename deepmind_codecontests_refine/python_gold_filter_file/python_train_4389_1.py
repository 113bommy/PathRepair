def decto26(n):
    a=[]
    while n>0:
        a.insert(0,n%26)
        n//=26
    return a
def f26todec(a):
    n=0
    l=len(a)-1
    for i in a:
        n+=i*(26**l)
        l-=1
    return n
def sum26(a,b,n):
    q=0
    c=[]
    for i in range(n+1):
        c.append(0)
    for i in range(n,0,-1):
        c[i]=(a[i-1]+b[i-1]+q)%26
        q=(a[i-1]+b[i-1]+q)//26
    c[0]+=q
    return c
def del26(a):
    n=len(a)
    q=a[0]
    c=[]
    for i in range(n):
        c.append(0)
    for i in range(n-1):
        c[i]+=a[i]//2
        if a[i]%2==1:
            a[i+1]+=26
    c[-1]=a[-1]//2
    if q<=1:
        c.pop(0)
    return c
abc='abcdefghijklmnopqrstuvwxyz'
k=int(input())
s=input()
a=[]
for i in s:
    a.append(abc.index(i))
sm=a
t=input()
a=[]
for i in t:
    a.append(abc.index(i))
tm=a
a=del26(sum26(sm,tm,k))
b=''
for i in a:
    b+=abc[i]
print(b)