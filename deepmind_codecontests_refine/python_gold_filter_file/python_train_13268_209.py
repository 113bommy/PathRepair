c=0
for _ in range(int(input())):
    a,b=map(int,input().split())
    if a+2<=b:
        c+=1
print(c)