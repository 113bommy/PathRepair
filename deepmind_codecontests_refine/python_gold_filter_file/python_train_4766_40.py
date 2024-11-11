x,y=map(int,input().split())
print('YNeos'[y%2==1 or x*4<y or x*2>y::2])