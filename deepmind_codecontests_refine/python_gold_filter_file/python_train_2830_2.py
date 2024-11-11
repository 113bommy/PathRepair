n = int(input())
s, t = input(), input()

ai, bi = [], []
for i in range(n):
    if s[i] != t[i]:
        if s[i] == 'a': ai.append(i + 1)
        else: bi.append(i + 1)

if (len(ai) + len(bi)) % 2 > 0:
    print(-1)
    exit(0)

print(len(ai) // 2 + len(bi) // 2 + (2 * (len(bi) % 2)))

while len(ai) >= 2:
    print(ai.pop(), ai.pop())
while (len(bi) >= 2):
    print(bi.pop(), bi.pop())

if (len(ai)) > 0:
    assert len(bi) > 0
    print(ai[0], ai[0])
    print(ai[0], bi[0])
