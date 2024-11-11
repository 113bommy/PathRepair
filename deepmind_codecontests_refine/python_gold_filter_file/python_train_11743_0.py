n = int(input())
lg = 0
while n>>lg >=1:
    lg += 1

a = [[0 for _ in range(n)] for __ in range(n)]
for i in range(n):
    for j in range(i+1,n):
        for k in range(lg):
            if (i>>k)&1!=(j>>k)&1:
                a[i][j] = k+1
                break

for i in range(n):
    for j in range(i+1,n):
        print(a[i][j], end = " ")
    print()
