b=int(input())
g=int(input())
n=int(input())
cnt=0
for i in range(b+1):
    for j in range(g+1):
        if(i+j==n):
            cnt+=1
print(cnt)            