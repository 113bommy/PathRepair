x,a,b=map(int,input().split())
print('delicious' if b<=a else 'safe' if b<=a+x else 'dangerous')
