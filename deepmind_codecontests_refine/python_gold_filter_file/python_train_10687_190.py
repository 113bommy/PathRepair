x,k = map(int, input().split())
for _ in range(k):
    if x%10 == 0:
        x = x//10
    else:
        x = x -1
print(x)