n = int(input())
x = int(input())

n -= 1
n %= 6

l = [[1, 2, 2, 1, 0, 0],
     [0, 0, 1, 2, 2, 1],
     [2, 1, 0, 0, 1, 2]]

for i in range(3):
    if l[i][n] == x:
        print(i)
        break
