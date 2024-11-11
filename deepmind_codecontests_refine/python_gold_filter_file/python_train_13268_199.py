c=0
for _ in range(int(input())):
    m,s=list(map(int,input().split()))
    if s-m>=2:
        c+=1
print(c)