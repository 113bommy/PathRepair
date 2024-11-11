n = int(input())
x = list(set(map(int,input().split())))
x = sorted(x)
flag = 1
ans = x[0]
for i in x:
    if i%ans:
        flag=0


if flag==0:
    print(-1)
else:
    print(ans)

