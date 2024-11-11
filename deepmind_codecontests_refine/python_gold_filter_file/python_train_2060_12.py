n = input()

a = n[::-1] + "0"

prev_a = int(a[0])
prev_b = 10 - int(a[0])

# dp[下の桁から][繰り上げるかどうか]
for i in range(1, len(a)):
    x = int(a[i])
    y = x + 1
    aa = min([x + prev_a, y + prev_b])
    bb = min([(10 - x) + prev_a, (10 - y) + prev_b])
    prev_a = aa
    prev_b = bb

print(min(aa, bb))