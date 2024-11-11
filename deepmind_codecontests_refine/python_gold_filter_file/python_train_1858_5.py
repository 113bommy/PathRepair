from collections import Counter
h, w = map(int, input().split())
A = []
for i in range(h):
    A.extend(list(input()))
cA = Counter(A)

l1 = h*w%2
l2 = (h//2)*(w%2) + (w//2)*(h%2)
l3 = (h//2)*(w//2)
if l1:
    for key, val in cA.items():
        if val%2==1:
            cA[key] -= 1
            break
for _ in range(l2):
    for key, val in cA.items():
        if val%4==2:
            cA[key] -= 2
            break
print('Yes' if sum(val%4 for val in cA.values()) == 0 else 'No')