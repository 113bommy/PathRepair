n=int(input())
cnt=0
for i in range(n):
    x, y=map(int, input().split())
    if y-x>=2:
        cnt+=1
print(cnt)