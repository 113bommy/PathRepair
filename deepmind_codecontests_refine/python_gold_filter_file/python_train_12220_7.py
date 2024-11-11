x, y = list(map(int, input().rstrip().split()))
# ans = 1 + 4 * (abs(x) - 1)
if (x == 0 and y == 0) or (x == 1 and y == 0):
    print(0)
elif x > 0 and (y in range(-1 * x + 2, x+1)):
    ans = 1 + 4 * (abs(x) - 1)
    print(ans)
elif y > 0 and (x in range(-1 * y, y)):
    ans = 1 + 4 * (y - 1)
    print(ans + 1)
elif x < 0 and (y in range(x-1, abs(x))):
    ans = 1 + 4 * (abs(x) - 1)
    print(ans + 2)
else:
    ans = 1 + 4 * (abs(y) - 1)
    print(ans+3)