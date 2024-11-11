r=0
for i in range(int(input())):
    a,b=map(int,input().split())
    if b-a>=2:
        r+=1
print(r)