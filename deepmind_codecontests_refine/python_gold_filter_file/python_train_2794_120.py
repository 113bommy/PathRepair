x,a,b = map(int,input().split())
print("B" if abs(x-b)<abs(x-a) else "A")