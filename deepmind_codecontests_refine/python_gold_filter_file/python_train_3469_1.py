#####change recurssion limit
import sys,threading
sys.setrecursionlimit(6100)
threading.stack_size()
thread=threading.Thread()
thread.start()
t=int(input())
zero=0
to=2
def solve(curr,pro,l,c,m,p):
    if pro==zero:
        return
    if curr=="p":
        pro*=p
        ans.append((pro,l))
        return
    if curr=="c":
        if c==zero:
            return
        pro*=c
        pro/=10**8
        if c<=v:
            if m!=0:
                m+=c/to
                p+=c/to
            else:
                p+=c
            c=zero
        else:
            if m!=zero:
                m+=v/to
                p+=v/to
            else:
                p+=v
            c-=v
        solve("c",pro,l+1,c,m,p)
        solve("m",pro,l+1,c,m,p)
        solve("p",pro,l+1,c,m,p)
    else:
        if m==zero:
            return
        pro*=m
        pro/=10**8
        if m<=v:
            if c!=zero:
                c+=m/to
                p+=m/to
            else:
                p+=m
            m=zero

        else:

            if c!=zero:
                c+=v/to
                p+=v/to
            else:
                p+=v
            m-=v
        solve("c",pro,l+1,c,m,p)
        solve("m",pro,l+1,c,m,p)
        solve("p",pro,l+1,c,m,p)
    return
while t:
    t-=1
    c,m,p,v=[int(float(x)*(10**8)) for x in input().split()]
    ans=[]
    solve("c",1,1,c,m,p)
    solve("m",1,1,c,m,p)
    solve("p",1,1,c,m,p)
    s=0
    for a in ans:
        s+=a[0]*a[1]
    print(s/10**8)

