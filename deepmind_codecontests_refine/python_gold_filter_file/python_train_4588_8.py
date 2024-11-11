n, x = [int(i) for i in input().split()]

while not (n == 0 and x == 0):
    test = [[i,j,k] for i in range(1, n+1) for j in range(i+1, n+1) for k in range(j+1, n+1) if i + j + k == x]
    print(len(test))
    n, x = [int(i) for i in input().split()]
