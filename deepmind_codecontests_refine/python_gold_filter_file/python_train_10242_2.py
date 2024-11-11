ans = [[True for i in range(3)] for j in range(3)] 
ip = []
for i in range(3):
    k = list(map(int, input().split()))
    ip.append(k)
for i in range(3):
    for j in range(3):
        if ip[i][j]%2==0:
            continue
        ans[i][j] =  not ans[i][j]
        if j-1>-1:
            ans[i][j-1] = not ans[i][j-1]
        if j+1<3:
            ans[i][j+1] = not ans[i][j+1]
        if i+1<3:
            ans[i+1][j] = not ans[i+1][j]
        if i-1>-1:
            ans[i-1][j] = not ans[i-1][j]
            
for i in range(3):
    for j in range(3):
        if ans[i][j]:
            print("1", end="")
        else:
            print("0", end="")
    print()