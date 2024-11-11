n,a,r=list(map(int,input().split()))
if r>0:
    for x in range(5555555):
        if r!=0:
            if a!=n:
                a+=1
                r-=1
            else:
                a=1
                r-=1
        else:
            break
    print(a)
else:
    for x in range(5555555):
        if r!=0:
            if a!=1:
                a-=1
                r+=1
            else:
                a=n
                r+=1
        else:
            break
    print(a)