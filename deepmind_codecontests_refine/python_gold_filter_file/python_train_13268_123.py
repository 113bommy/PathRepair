c=0
for _ in range(int(input())):
    a,b=map(int,input().split())
    if abs(a-b)>=2:
        c+=1
print(c)