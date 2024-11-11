a,b = map(int,input().split())
c = list(map(int,input().split()))
cnt = 0
for i in c:
    if i > b:
        cnt+=2
    else:
        cnt+=1
print(cnt)