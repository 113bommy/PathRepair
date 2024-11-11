
t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    l.sort()
    m1=l[-1]
    m2=l[-2]
    lmax=min(m1,m2)
    if(lmax > len(l)-2 ):
        print(len(l)-2)
    elif(len(l)-2 == lmax):
        print(len(l)-3)
    else:
        print(lmax-1)
    
