k = int(input())
s1 = input()
s2 = input()
a1 = []
a2 = []
delta = []
for i in range(k):
    a1.append(ord(s1[i])-97)
    a2.append(ord(s2[i])-97)
    delta.append(a2[i]+a1[i])
for i in range(k-1):
    delta[i + 1] += 26 * (delta[i] % 2)
    delta[i] = delta[i] // 2
delta[k-1] = delta[k-1] // 2

i = k-1
while i > 0:
    if delta[i] >= 26:
        delta[i-1] += 1
        delta[i] -= 26
    else:
        i -= 1

for i in range(k):
    print(chr(delta[i]+97), end='')

