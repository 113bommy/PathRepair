def isprime(num):
    p=True
    for i in range(1, num):
        if num%i==0 and i!=1:
            p=False
    return p

def dprime(a):
    c=0
    b=False
    for i in range(2, a):
        if a%i==0 and isprime(i)==True :
            c+=1
    if c==2:
        b=True
    return b

n=int(input())
    
if n<=3000 and n>0:
    count=0
    for j in range(n+1):
        if dprime(j)==True:
            count+=1
            
            
    print(count)

    