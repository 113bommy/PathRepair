t=int(input())
i=int(1)
while i<=t :
    a,b,k=input().split(" ")
    a=int(a)
    b=int(b)
    k=int(k)
    
    if k%2==0 :
        sum1=int(a*(k//2))
        sum2=int(b*(k//2))
        print(sum1-sum2)
        
    else :
        sum1=int((a*((k//2)))+a)
        sum2=int(b*(k//2))
        print(sum1-sum2)
    i=i+1