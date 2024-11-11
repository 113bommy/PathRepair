n = int(input())
list1 = sorted(list(map(int, input().split())))
print(list1[(n - 1) // 2])