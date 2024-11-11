n = int(input())
ans = [[0 for i in range(n)] for j in range(n)]
ptr = 0
for i in range(n):
    if i%2 == 0:
        for j in range(n):
            ans[i][j] = ptr
            ptr+=1
    else:
        for j in range(n-1,-1,-1):
            ans[i][j] = ptr
            ptr+=1
for i in range(n):
    for j in range(n):
        print(ans[j][i]+1,end = " ")
    print()