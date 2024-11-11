t=int(input())
x=0
for i in range(t):
    s=input()
    if s=='X++' or s=='++X':
        x=x+1
    else:
        x=x-1
print(x)