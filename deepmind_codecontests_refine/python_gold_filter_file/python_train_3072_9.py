def ur(k, x, b):
    return k * x + b

n = int(input())
lst = []
x1, x2 = map(int, input().split())
for i in range(n):
    k, b = map(int, input().split())
    lst.append((ur(k, x1, b), ur(k, x2, b)))
lst.sort()    
for i in range(1, n):
    if (lst[i][0] > lst[i - 1][0] and lst[i][1] < lst[i - 1][1]) or (lst[i - 1][0] < lst[i][0] and lst[i - 1][1] > lst[i][1]):
        print('YES')
        break
else:
    print('NO')
