x,a,b=map(int,input().split())
if a-b>=0:print('delicious')
elif a-b < 0 and a+x>=b:print('safe')
else:print('dangerous')