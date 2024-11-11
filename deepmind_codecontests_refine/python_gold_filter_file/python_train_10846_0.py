import sys

def twoDiv(n):
    at = 0
    while n%2 == 0:
        n = n//2
        at += 1
    return at

total = int(next(sys.stdin))
nums = [int(k) for k in next(sys.stdin).split()]

comps = {}
largest = 0
for n in nums:
    k = twoDiv(n)
    if k not in comps.keys():
        comps[k] = set()
    comps[k].add(n)
    largest = max(largest, len(comps[k]))

good = -1
for c in comps:
    if len(comps[c]) == largest:
        good = c
        break
del comps[good]

ans = set()
for c in comps:
    ans = ans|comps[c]
ans = sorted(list(ans))
print(total - largest)
at = 0
for k in ans:
    at = at + 1
    if at == total - largest:
        print(k, end="\n")
        quit()
    print(k, end=" ")
