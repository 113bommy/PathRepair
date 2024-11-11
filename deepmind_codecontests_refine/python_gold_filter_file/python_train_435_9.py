import sys
t=int(sys.stdin.readline())
for _ in range(t):
    A,B=sys.stdin.readline().split()
    a,b=list(A),list(B)
    c=a.copy()
    c.sort()
    #print(c,b)
    #print(c>=b)
    if c>=b:
        print('---')
    else:
        n=len(a)
        #print(c)
        #print(a)
        for i in range(n):
            if c[i]!=a[i]:
                break
        for j in range(n-1,-1,-1):
            if a[j]==c[i]:
                break
        a[i],a[j]=a[j],a[i]
        if a<b:
            print(''.join(x for x in a))
        else:
            print('---')
