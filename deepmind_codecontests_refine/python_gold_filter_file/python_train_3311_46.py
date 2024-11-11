r,g,b,n=[int(i) for i in input().split(" ")]

res = 0
for i in range(0,n+1,r):
    for j in range(i,n+1,g):
        if (n-j) % b == 0:
            res += 1

print(res)

