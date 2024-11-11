n,x=int(input()),input()
o=x.count("1")
if o==1:
    for i,v in enumerate(x):
        if v=="1":print(0)
        else:
            if i!=n-1:
                if x[-1]=="0":print(1)
                else:print(2)
            else:print(2)

else:
    m=o-1
    M=o+1
    mp,mm={0:1},{0:1}
    for i in range(1,n):
        mp[i]=mp[i-1]*2%M
        mm[i]=mm[i-1]*2%m
    A=int(x,2)
    a=A%m
    b=A%M
    rest={0:0}
    for i in range(1,o+1):
        rest[i]=1+rest[i%bin(i).count("1")]
    for i,v in enumerate(x):
        if v=="1":
            print(1+rest[(a-mm[n-i-1])%m])
        else:
            print(1+rest[(b+mp[n-i-1])%M])
