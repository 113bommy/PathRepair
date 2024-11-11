v = 'aeiouy'
n = int(input())
s = input()
res = [s[0]]
i = 0
while i < n:
    j = i + 1
    if s[i] in v:
        while j < n and s[j] in v: j += 1
    if j < n:
        res.append(s[j])
    i = j
print(''.join(res))