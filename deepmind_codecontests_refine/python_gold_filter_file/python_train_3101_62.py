a,b,c = map(int,input().split())

if (4*a*b)<(max((c-a-b),0)**2):
    print('Yes')
else:
    print('No')