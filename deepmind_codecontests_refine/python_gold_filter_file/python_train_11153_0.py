n = int(input())
s = input()
mask = ['RGB', 'RBG', 'BRG', 'BGR', 'GBR', 'GRB']
ans = n
num = -1
for i in range(6):
    ai = 0
    for j in range(n):
        ai += (s[j] != mask[i][j % 3])
    ans = min(ans, ai)
    if ans == ai:
        num = i
print(ans)
print(mask[num] * (n // 3) + mask[num][0] * (n % 3 > 0) + mask[num][1] * (n % 3 > 1))
