n = int(input())
ans = [8,4,2,6]
if n == 0:
    print(1)
else:
    print(ans[(n-1) % 4])
