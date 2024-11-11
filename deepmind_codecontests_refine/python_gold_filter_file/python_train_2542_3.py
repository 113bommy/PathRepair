
n = int(input())
pile = [int(x) for x in input().split()]
pile.sort()

res = 1
for i in range(n):
    x = i // res
    if pile[i] < x:
        res += 1
print(res)