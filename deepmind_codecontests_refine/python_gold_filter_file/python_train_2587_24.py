k,s=map(int,input().split())
t=0
for x in range(k+1):
    for y in range(k+1):
        if 0<=s-x-y<=k:
            t+=1
print(t)