n=int(input())
e=0
for i in range (0,n):
    ch=str(input())
    if ch=="X++" or ch=="++X":
        e+=1
    elif ch=="X--" or ch=="--X":
        e-=1
print(e)