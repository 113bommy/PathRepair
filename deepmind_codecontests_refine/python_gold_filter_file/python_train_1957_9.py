n = int(input())-65
s = input()
ans = ''
for x in s:
    ans += chr((ord(x)+n)%26 + 65)
print(ans)