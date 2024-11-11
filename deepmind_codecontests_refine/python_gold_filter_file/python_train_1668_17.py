x,y = map(int,input().split())
while y:
    x,y = y, x%y
print(x)