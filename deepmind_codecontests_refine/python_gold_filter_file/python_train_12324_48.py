p=int(input())
c=0
for i in range(p):
    n=input()
    if n=="X++" or n=="++X":
        c=c+1
    else:
        c=c-1
print(c)