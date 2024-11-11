import string

s, k = input().split()
max_changes = int(k)
len_s = len(s)

alpha = string.ascii_lowercase
bonuses = { ch: { ch: 0 for ch in alpha } for ch in alpha }
for i in range(int(input())):
    a, b, x = input().split()
    bonuses[a][b] = int(x)

def improve(current, changed, a, b, score):
    if b not in current[changed] or current[changed][b] < score:
        current[changed][b] = score
        #print('%c: current[%d][%c] <- %d' % (a, changed, b, score))

current = [ { s[0]: 0 }, { ch: 0 for ch in alpha } ]
for pos in range(1, len_s):
    previous = current
    len_current = min(len(previous) + 1, max_changes + 1)
    current = [ {} for i in range(len_current) ]
    for changed, scores in enumerate(previous):
        for a, score in scores.items():
            for b, bonus in bonuses[a].items():
                if b == s[pos]:
                    if changed < len(current):
                        improve(current, changed, a, b, score + bonus)
                elif changed + 1 < len(current):
                    improve(current, changed + 1, a, b, score + bonus)

best = -(10 ** 5)
for changed, scores in enumerate(current):
    for score in scores.values():
        best = max(best, score)
print(best)
