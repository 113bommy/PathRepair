n = int(input())
s = input()

i = 1
while i < n:
    if s[i] < s[i-1]:
        res = s[:i-1] + s[i:]
        print(res if res < s else s)
        break
    i += 1
else:
    print(s[:-1])