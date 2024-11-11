a,b,c=map(int,input().split())
print("B" if abs(b-a)>abs(c-a) else "A")