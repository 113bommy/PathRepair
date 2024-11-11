s = input()
t = input()

def search(s, t):
    indext = 0
    pos = [-1]
    for i in range(len(s)):
        if indext < len(t) and s[i] == t[indext]:
            pos += [i]
            indext += 1
        if indext == len(t):
            return pos
        
pos = search(s, t)
right = len(s) - 1
ans = right - pos[-1]

for i in range(len(t))[::-1]:
    while s[right] != t[i]:
        right -= 1
    right -= 1
    ans = max(ans, right - pos[i])
print(ans)