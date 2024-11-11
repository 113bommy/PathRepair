c=0
for i in range(int(input())):
    n,m=map(int,input().split())
    if m-n>=2:
        c+=1
print(c)