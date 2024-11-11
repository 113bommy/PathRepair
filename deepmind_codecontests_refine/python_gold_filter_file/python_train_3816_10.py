n,m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(list(input()))
p= "Yes"
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'W':
            if i != 0 and arr[i-1][j] == 'S':
                p = 'No'
                break
            else:
                if i != 0 and arr[i-1][j] != 'W':
                    arr[i-1][j] = 'D'

            if i != n-1 and arr[i+1][j] == 'S':
                p = 'No'
                break
            else:
                if i != n-1 and arr[i+1][j] != 'W':
                    arr[i+1][j] = 'D'

            if j != 0 and arr[i][j-1] == 'S':
                p = 'No'
                break
            else:
                if j != 0 and arr[i][j-1] != 'W':
                    arr[i][j-1] = 'D'


            if j != m-1 and arr[i][j+1] == 'S':
                p = 'No'
                break
            else:
                if j != m - 1 and arr[i][j+1] != 'W':
                    arr[i][j+1] = 'D'

    if p == "No":
        break
if p== "Yes":
    print(p)
    for i in range(n):
        print(''.join(arr[i]))
else:
    print(p)



