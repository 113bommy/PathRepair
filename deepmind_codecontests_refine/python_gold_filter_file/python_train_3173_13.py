n,k= map(int,input().split())
l=list(map(int,input().split()))
ma=max(l)
mi=min(l)
t= ma-mi
if t<=k:
    print('YES')
    for i in range(0,len(l)):
        j=mi
        while j>0:
            print(1,end=" ")
            j-=1
        a=1
        b=l[i]
        while b>mi:
            print(a,end=" ")
            a+=1
            b-=1
        print()

else:
    print('NO')