def NOD(a,b):
    if (a==b)or(b==0):
        return a
    else:
        return NOD(b,a%b)

t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    w=a[0]
    q=a[1]
    e=0
    t=0
    for j in range(0,n,2):
        w=NOD(w,a[j])
    for j in range(1,n,2):
        if w<=a[j]:
            if a[j]%w==0:
                e=-1
        q=NOD(q,a[j])
    for j in range(0,n,2):
        if q<=a[j]:
            if a[j]%q==0:
                t=-1
                break
    if w==1:
        e=-1
    if q==1:
        t=-1

    if t!=-1:
        print(q)
    else:
        if e!=-1:
            print(w)
        else:
            print(0)