a,m=map(int,input().split())
f=1 
while a<=10**7:
    a1=a+a%m 
    if a1==a:
        f=0 
        break 
    a=a1 
if f:
    print('No')
else:
    print('Yes')