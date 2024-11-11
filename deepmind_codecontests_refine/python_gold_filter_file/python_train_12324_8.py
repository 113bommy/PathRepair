n=int(input())
x=0
for i in range(n):
    exp=input()
    if exp=='X++' or exp=='++X':
        x+=1
    else:
        x-=1
print(x)
    
