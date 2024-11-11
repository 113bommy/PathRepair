X,Y =map(int,input().split())
cnt = 1
while X <= Y:
    X *= 2
    cnt += 1
print(cnt-1)