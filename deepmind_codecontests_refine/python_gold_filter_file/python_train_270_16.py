n = int(input())
ng = 3
flag = True
for i in range(n):
    k = int(input())
    if k == ng:
        flag = False
    else:
        for j in range(1, 4):
            if j != ng and j != k:
                ng = j
                break

if flag:
    print("YES")
else:
    print("NO")