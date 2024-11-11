n=int(input())
c=0
for _ in range(n):
    s=input()
    if(s=="++X" or s=="X++"):
        c+=1
    else:
        c-=1
print(c)