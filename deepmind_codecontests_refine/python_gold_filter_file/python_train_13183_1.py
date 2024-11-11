import sys
a=sys.stdin.readline().split()[0]
b=sys.stdin.readline().split()[0]
a=[int(x) for x in a]
b=[int(x) for x in b]
def mov(a,x1,x2):
    a.insert(x1,a.pop(x2))
    return a
def min(a):
    m=9
    for i in a:
        x=int(i)
        if x<m:
            m=x
    return m
def max(a):
    m=0
    for i in a:
        x=int(i)
        if x>m:
            m=x
    return m
def maxb(a,b):#maxb([1,2,3,4],3)=2
    m=-1
    for i in a:
        x=int(i)
        if x>m and x<b:
            m=x
    return m
def ens(a):
    f=[x for x in a[:i+1]]
    d=[x for x in a[i+1:]]
    d.sort()
    d.reverse()
    f.extend(d)
    return f
def f(i,l):
    global a
    global b
    global e
    global t
    global w
    if e==0:
        return 0
    if i==l:
        if a[i]<b[i]:
            return a
        else:
            e=0
            return -1
    if a[i]!=b[i]:
        x=-1
        if b[i] in a[i:]:
            if t==0:
                w+=1
            x=b[i]
            mov(a,i,i+a[i:].index(x))
        elif maxb(a[i+0:],b[i]) in a[i+0:]:
            t=1
            x=maxb(a[i+0:],b[i])
            mov(a,i,i+a[i:].index(x))
            a=ens(a)
            return 2
        else:
            e=0
            return 0
    else:
        if t==0:
            w+=1
    return 1
t=0
w=0
e=1
a1=[x for x in a]
b1=[x for x in b]
a1.sort()
b1.sort()
if a1==b1:
    c1=int("".join([str(x) for x in b]))
    print(c1)
else:
        
    if len(a)==len(b):        
        for i in range(len(a)):
            q=f(i,len(a))
            if q==2:
                r=2
                break
            if q==0:
                break
            if q==-1:
                q=2
                break
        if q!=2:
            r=0
            for i in range(w+0,-1,-1):
                if i>len(a)-1:
                    break
                if a[i]<b[i]:
                    a=ens(a)
                    r=1
                    break
                if maxb(a[i+1:],b[i]) in a[i+1:]:
                    x=maxb(a[i+1:],b[i])
                    mov(a,i,i+a[i:].index(x))
                    a=ens(a)
                    r=1
                    break
    else:
        a.sort()
        a.reverse()
    c1=int("".join([str(x) for x in a]))
    print(c1)