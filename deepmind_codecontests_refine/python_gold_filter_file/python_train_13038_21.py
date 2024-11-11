t = int(input())

for _ in range(t):
    row, col = (int(var) for var in input().split(" "))

    if col%2:
        print(row*(col//2)+  row//2+  row%2)
    else:
        print(row*((col//2)))