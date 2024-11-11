n, m, k = map(int, input().split())

num = (k-1)//2
row = num//m + 1
col = num % m + 1

print(row, col,  "L" if k%2 else "R")
