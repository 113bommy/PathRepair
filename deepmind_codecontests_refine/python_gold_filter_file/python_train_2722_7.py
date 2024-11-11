n = int(input())

arr = [list(input()) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if i == 0 or i == n-1 or j==0 or j == n-1: continue
        if arr[i][j] == '#': continue

        if arr[i-1][j] == '#' or arr[i+1][j]=='#' or arr[i][j-1] == '#' or arr[i][j+1]=='#':continue

        arr[i][j] = '#'
        arr[i][j+1] = '#' 
        arr[i][j-1] = '#' 
        arr[i+1][j] = '#' 
        arr[i-1][j] = '#' 
f = True
for i in arr:
    if '.' in i:
        f = False
        break


print("YES" if f else "NO")