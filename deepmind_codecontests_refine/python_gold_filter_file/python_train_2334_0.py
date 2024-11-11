n = int(input())

memo = {}

for _ in range(4):
    s = input()
    for i in s:
        if i != '.':
            if i not in memo:
                memo[i] = 1
            else:
                memo[i] += 1

res = True

for k, v in memo.items():
    if v > n*2:
        res = False

if res:
    print("YES")
else:
    print("NO")
        

