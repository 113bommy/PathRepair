a=int(input())
r=0
for i in range(a):
    b=input()
    if(b=='++X' or b=='X++'):
        r=r+1
    else:
        r=r-1
print(r)