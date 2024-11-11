n = input()
h = [0]
A = list(map(int, input().split()))
A.sort()

for x in A:
    if x < min(h):
        h += [1]
    else:
        h[h.index(min(h))]+=1
print(len(h))
