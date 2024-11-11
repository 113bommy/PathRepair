n, x = map(int, input().split())
a = list(map(int, input().split()))
a = sorted(a)
num = 0
if x in a:
    num += 1
for i in range(100):
    if i >= x:
        break
    if i not in a:
        num += 1

print(num)