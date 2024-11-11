import sys

n = int(input())
s = input()
ans = ''
lst0 = 'a'
lst1 = 'a'
for i in range(0, n):
    if (s[i] >= lst0):
        ans += '0'
        lst0 = s[i]
    elif s[i] >= lst1:
        ans += '1'
        lst1 = s[i]
    else:
        print("NO\n")
        sys.exit()
print("YES\n")
print(ans)

