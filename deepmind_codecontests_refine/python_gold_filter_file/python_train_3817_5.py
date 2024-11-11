n=int(input())
b=str(input())
if int(b)!=0:
    b=int(b)
    li=[]
    while b!=0:
        r=b%10
        b=b//10
        li.append(r)
    li.sort()    
    p=li.count(0)
    
    o=li.count(1)
    if o!=0:
        a=10**(p)
        print(str(a))
else:
    print(b)