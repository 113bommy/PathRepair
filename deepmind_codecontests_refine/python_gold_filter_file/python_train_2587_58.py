k,s=map(int,input().split())
p=0
for x in range(k+1):
    for y in range(k+1):
        if 0<=s-x-y<=k:
            p+=1
print(p)