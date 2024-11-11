a,b,c=list(map(int,input().split()))
print("A" if abs(a-c)>abs(a-b) else "B")