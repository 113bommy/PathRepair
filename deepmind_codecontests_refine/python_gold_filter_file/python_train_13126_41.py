n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

print("Yes" if sum(y) <= sum(x) else "No")