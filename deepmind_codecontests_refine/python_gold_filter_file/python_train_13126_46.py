n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
if sum(x) >= sum(y):
    print("Yes")
else:
    print("No")
