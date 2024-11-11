s = list(input())
cnt, i = 0, 1
l = len(s)

while i < l:
    if s[i] == s[i-1]:
        cnt += 1
        i += 2
    i += 1

print(l-cnt)