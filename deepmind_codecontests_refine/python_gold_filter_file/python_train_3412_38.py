k=int(input())

cur=0
for i in range(k+2):
    cur=(cur*10+7)%k
    if cur==0:
        print(i+1)
        exit()

print(-1)