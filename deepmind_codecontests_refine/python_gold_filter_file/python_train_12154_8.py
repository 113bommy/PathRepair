n,m = map(int, input().split())
arr = []
b = []
for i in range(n):
    a = list(map(lambda x: 100 if x == '*' else(0 if x == '.' else int(x)), list(input())))
    j = -1
    while j < m:
        try:
            j = a.index(100, j+1)
            b.append([i, j])
        except:
            break
    arr.append(a)

for i,j in b:
    j1,j2 = max(0,j-1), min(j+1, m-1)
    if i > 0:
        i1=i-1
        arr[i1][j1:j2+1] = [x-1 if x != 100 else x for x in arr[i1][j1:j2+1]]
    
    arr[i][j1:j2+1] = [x-1 if x != 100 else x for x in arr[i][j1:j2+1]]

    if i < n-1:
        i1=i+1
        arr[i1][j1:j2+1] = [x-1 if x != 100 else x for x in arr[i1][j1:j2+1]]

for i,j in b:
    arr[i][j] = 0

for i in range(n):
    if any(arr[i]):
        print('NO')
        exit(0)
        
print('YES')