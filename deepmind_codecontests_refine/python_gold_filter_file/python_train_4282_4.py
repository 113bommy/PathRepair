n,s=map(int,input().split(' '))
a=list(map(int,input().split(' ')))
a.sort()
h=sum(a)
if h>s:
    min=a[0]
    f=h-min*n
    if f>=s:
        print(min)
    else:
        print((h-s)//n)
elif h==s:
    print(0)
else:
    print(-1)
    
        
        
        
