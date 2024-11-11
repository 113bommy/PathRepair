n, m = map(int, input().split())
s = input()
t = input()
arr = []
#                     поменять индексы на +1
def check(i):
    iter = 0
    arr.append([])
    arr[i].append(0)
    while iter < n:
        if t[i + iter] != s[iter]:
            arr[i][0] += 1
            arr[i].append(iter)
        iter += 1



for i in range(m - n + 1):
    check(i)
#print(arr)
min = 20000000
for a in arr:
    if a[0] < min:
        min = a[0]
for a in arr:
    if a[0] == min:
        iter = 0
#        print(arr[a][1])
        while iter < len(a):
            if iter == 0:
                print(a[iter])
            if iter != 0:
                print(a[iter] + 1, end = ' ')
            iter += 1
        break
