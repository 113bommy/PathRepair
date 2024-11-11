n,a,b=map(int, input().split())
t=list(map(int, input().split()))
sc=0; p=0
for i in range(n):
    if t[i]==1:
        if a>0:
            a-=1
        elif b>0:
            b-=1
            p+=1
        elif p>0:
            p-=1
        else:
            sc+=1
    else:
        if b>0:
            b-=1
        else:
            sc+=2
    #print(a,b,p)
print(sc)