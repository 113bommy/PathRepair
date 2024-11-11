a, b, c = map(int, input().split())

ans = []
for i in range(1, 82):
    x = b*(i**a)+c
    if 0 < x < 10**9 and sum(map(int,str(x))) == i:
        ans.append(x)

print(len(ans))
print(*ans)
