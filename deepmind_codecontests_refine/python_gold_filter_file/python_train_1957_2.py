n = int(input())
s = input()
ans = ""
for x in s:
    ans += chr((ord(x)-65+n)%26 + 65)
print(ans)