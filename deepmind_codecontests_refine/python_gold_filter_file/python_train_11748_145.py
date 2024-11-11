x,a,b = (int(i) for i in input().split())
print('delicious' if a-b>=0 else 'safe' if x >= b-a else 'dangerous') 
