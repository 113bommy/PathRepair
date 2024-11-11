ls = list(map(int, input().split(" ")))
a = max(ls)
ls.remove(a)
asum = sum(ls)
if asum > a:
    time = 0
else:
    time = abs(a- asum + 1)
print(time)