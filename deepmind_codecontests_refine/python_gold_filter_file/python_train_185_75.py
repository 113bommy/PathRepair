def isprime(n):
    if(n==2 or n==3):
        return True
    if(n<=1):
        return False
    if(n%2==0 or n%3==0):
        return False
    x=5
    while(x*x<=n):
        if(n%x==0 or n%(x+2)==0):
            return False
        x+=6
    return True
n,p=map(int,input().split())
if(n==1):
    print(p)
else:
    ans=1
    for i in range(2,int(p**0.5)+1,1):
        num=p
        count=0
        while(num%i==0):
            num=num//i
            count+=1
        if(count>=n):
            ans=i
    print(ans)