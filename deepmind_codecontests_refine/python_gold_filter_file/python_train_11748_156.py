x,a,b=map(int,input().split())
print('delicious' if a>=b else 'dangerous' if b>a+x else 'safe')