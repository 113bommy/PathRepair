A,B,C,D =map(int,input().split())
while C>0 and A>0:
    C-=B
    A-=D
print("Yes" if C<=0 else "No")

