a,b,c=map(int,input().split())
print("A" if abs(a-b)<abs(c-a) else "B")