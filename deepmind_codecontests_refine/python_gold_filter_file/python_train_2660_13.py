ans = 'IMPOSSIBLE'
sticks = list(map(int, input().split()))
for num1 in range(2):
    for num2 in range(num1 + 1, 3):
        for num3 in range(num2 + 1, 4):
            if sticks[num1] + sticks[num2] > sticks[num3] > abs(sticks[num1] - sticks[num2]):
                ans = 'TRIANGLE'
            elif (sticks[num1] + sticks[num2] == sticks[num3] or sticks[num3] == abs(sticks[num1] - sticks[num2])) and\
                    ans != 'TRIANGLE':
                ans = 'SEGMENT'
print(ans)
