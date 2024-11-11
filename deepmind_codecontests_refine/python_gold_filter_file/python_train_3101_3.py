a,b,c=map(int,input().split(' '))
if 4*a*b>=(c-(a+b))**2 or a+b>c:
    print('No')
else:
    print('Yes')