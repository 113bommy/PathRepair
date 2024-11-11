x,y = map(int,input().split())

if x*2 <= y <= x*4 and y%2 == 0:
    print('Yes')
else:
    print('No')