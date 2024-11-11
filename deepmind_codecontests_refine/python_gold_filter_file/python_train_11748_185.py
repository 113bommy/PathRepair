x,a,b=map(int,input().split())
print('delicious' if b-a<=0 else 'dangerous' if x<b-a else 'safe')