mm = 10**9
a, b, c = list(map(int, input().split()))
arr = []
for k in range(0, 82):
    ans = b*(k**a) + c
    if ans > 0:
        if sum(list(map(int, list(str(ans))))) == k and ans < mm:
            arr.append(ans)
print(len(arr))
print(*arr)