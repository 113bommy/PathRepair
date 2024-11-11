n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
print(["Yes", "No"][sum(x) < sum(y)])