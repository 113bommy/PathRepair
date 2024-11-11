x,y=map(int,input().split())
if x%3==0 or y%3==0 or (x+y)%3==0:
    print('Possible')
else:
    print('Impossible')