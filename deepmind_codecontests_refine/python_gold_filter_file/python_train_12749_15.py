import sys

it = iter(sys.stdin.read().splitlines())
n,l = [int(x) for x in next(it).split()]
numbers = [int(x) for x in next(it).split()]
numbers.sort()
dif = 0
tempDif = 0
for i in range(len(numbers)-1):
    subs = numbers[i+1] - numbers[i]
    if subs > dif:
        dif = subs
dif = dif/2.0
if numbers[0] > dif:
    dif = numbers[0]
if numbers[n-1] + dif < l:
    dif = l - numbers[n-1]
print(dif)