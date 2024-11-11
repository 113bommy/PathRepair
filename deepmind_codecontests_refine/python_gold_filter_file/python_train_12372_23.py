import copy
n = int(input())
l = [list(map(int,input().split())) for i in range(n)]
l1 = copy.deepcopy(l)

for k in range(n):
    for i in range(n):
        for j in range(n):
            if l[i][j] > l[i][k]+l[k][j]:
                print(-1)
                exit()

            elif l[i][j] == l[i][k]+l[k][j]:
                if i != k and k != j :
                    l1[i][j] = 0
ans = 0
for i in l1:
    for j in i:
        ans += j
print(ans//2)
