n = int(input())

s = list(input())
t = list(input())

ans = 0

moves = []

for i in range(n):
    if s[i] != t[i]:
        if not (t[i] in s[i:]):
            ans = -1
            moves = []
            break
        ind = s[i:].index(t[i]) + i
        
        del(s[ind])
        s.insert(i, t[i])
        ans += ind-i
        k = ind-1
        while k >= i:
            moves.append(k+1)
            k -= 1


print(ans)
for i in moves:
    print(i, end = " ")
