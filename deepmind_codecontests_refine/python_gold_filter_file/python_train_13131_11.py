s1 = input().lower()
s2 = input().lower()
ans = 0
for i in range(len(s1)):
    if ord(s1[i]) > ord(s2[i]):
        ans = 1
        break
    if ord(s1[i]) < ord(s2[i]):
        ans = -1
        break
print(ans)