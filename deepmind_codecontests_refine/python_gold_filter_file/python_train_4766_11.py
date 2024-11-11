X, Y = map(int, input().split())
if (2*X <= Y <= 4*X) & (Y%2==0):
    print('Yes')
else:
    print('No')