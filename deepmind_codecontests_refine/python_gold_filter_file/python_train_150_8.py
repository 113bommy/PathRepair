n = int(input())
s = input()
f = False
for i in range(n):
    if s[i] == '*':
        for j in range(1, n//4 + 1):
            if (i+4*j < n) and (s[i] == s[i+j] == s[i+2*j] == s[i+3*j] == s[i+4*j]):
                f = True
                break
if f:
    print('yes')
else:
    print('no')