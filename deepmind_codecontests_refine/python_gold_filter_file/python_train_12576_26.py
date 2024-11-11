n = int(input())
s = [input() for _ in range(n)]
a = 0
b = 0
ab = 0
a_b = 0
for i in s:
    if i[0] == 'B' and i[-1] == 'A':
        a_b += 1
    if i[0] == 'B':
        b += 1
    if i[-1] == 'A':
        a += 1
    for j in range(len(i)-1):
        if i[j:j+2] == 'AB':
            ab += 1
if a_b == a == b != 0:
    b -= 1
print(ab+min(a, b))