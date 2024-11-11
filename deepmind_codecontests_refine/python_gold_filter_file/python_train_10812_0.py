def dist(c):
    return (ord('z') - ord(c) + 1) % 26

s = list(input())
k = int(input())
i = 0
while 0 < k and i < len(s):
    d = dist(s[i])
    if d <= k:
        k -= d
        s[i] = 'a'
    i += 1

s[-1] = chr((ord(s[-1]) + (k % 26)))
print(''.join(s))
