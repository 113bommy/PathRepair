s=int(input())
x=""
while s!=0:
    x=str(s%2)+x
    s=-(s//2)
print(0 if x=="" else x)