def isprime(n):
    flag=False
    for i in range(2,n-1):
        if n%i==0:
            flag=True
    return(flag)
n=int(input())
if n%2==0 and isprime(int(n/2))==True:
    print(int(n/2),int(n/2))
else:
    value=0
    for i in range(1,n):
        k=n//2+i
        if isprime(n-k)==True and isprime(k)==True:
            l=n-k
            print(int(k),int(l))
            break
        else:
            continue