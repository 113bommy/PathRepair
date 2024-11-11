n = input()
arr = list(map(int, input().split(" ")))
c = list(map(int, input().split(" ")))
a, b = c[0], c[1]
print(sum(arr[a - 1:b - 1]))