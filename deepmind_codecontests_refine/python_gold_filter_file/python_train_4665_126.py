n = int(input())
b = sorted(list(map(int, input().split())))
print(b[(n//2)] - b[(n//2)-1])