l = input()
ans = 0
for i in range(len(l)):
    if l[i] == 'A':
        ans += l[:i].count('Q') * l[i:].count('Q')
print(ans)