n=int(input())
x=0
for i in range(n):
    a=input()
    if a=='++X' or a=='X++':
        x=x+1
    else:
        x=x-1
print(x)
