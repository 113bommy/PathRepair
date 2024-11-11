n=int(input())
a=[]
for i in range(n):
    f=list(map(int,input().split()))
    s=0
    k=0
    if f[0]>=f[2]:
        d='-1'
        if f[1]==1000000000:
            d=d+' '+'1000000000'
            a.append(d)
        else:
            d = d + ' ' + str(f[1])
            a.append(d)
    elif f[0]*f[1]<=f[2]:
        if f[1]==1000000000:

            d='1'
        else:
            d=f[0]*f[1]+1
        d=str(d)+' '+'-1'
        a.append(d)
    else:
        s=1
        k=f[0]*f[1]-f[2]
        if k >0:
            k=f[1]
        else:
            k=1
        if f[1]==1000000000:

            d=str(s)+' '+str(1000000000)
            a.append(d)
        else:
            d = str(s) + ' ' + str(k)
            a.append(d)
for i in a:
    print(i)
