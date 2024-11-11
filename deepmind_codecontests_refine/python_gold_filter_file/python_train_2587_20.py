k,s=map(int,input().split())
n=0
for x in range(k+1):
    for y in range(k+1):
        if 0<=s-x-y<=k:
            n+=1
print(n)