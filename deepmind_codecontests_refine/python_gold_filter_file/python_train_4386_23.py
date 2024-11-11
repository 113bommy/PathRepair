n = int(input())
s = input()
idx = -1
for i in range(n - 1):
    if s[i + 1] < s[i]:
        idx = i
        break
if idx != -1:
    print(s[:idx] + s[idx + 1:])
else:
    print(s[:-1])