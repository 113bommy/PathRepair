n=int(input())
k=int(input())
a=int(input())
b=int(input())

if k==1:
    print((n-1)*a)
else:
    x=n
    count=0
    while x>1:
        if x>=k:
            if x%k==0:
                if (x-x//k)*a>b:
                    count+=b
                else:
                    count+=(x-x//k)*a
                x=x//k
            else:
                r=x%k
                count+=r*a
                x=x-r
        else:
            count+=(x-1)*a
            x=1
    print(count)