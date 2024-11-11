a=input()
s=''
n=0
s+=a[::-1]
if s!=a:
    print(len(a))
elif s==a:
    n=len(a)
    x=s
    while x==x[::-1] and n>0:
        n-=1
        s=s[:n]
        x=s
    print(n)

    
