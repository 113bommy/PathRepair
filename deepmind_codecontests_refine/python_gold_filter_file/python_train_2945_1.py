def prime(n):
    if n == 2:
        return True
    for i in range(2, n):
        if n%i == 0:
            return False

    return True

for _ in range(int(input())):
    n = int(input())
    matrix = [[0]*n for i in range(n)]

    x = 0
    flag = not prime(n)
    b = n-1

    if flag:
        while True:
            x += 1
            if prime(x):
                continue
            else:
                if prime(x+b):
                    break
    else:
        x = 1
            

    for i in range(n):
        for j in range(n):
            if i == j:
                matrix[i][j] = x
            else:
                matrix[i][j] = 1


    for i in range(n):
        print(*matrix[i])
