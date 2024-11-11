input()
s = input()
t = 0
l = 0
e = -1
for i in range(len(s)):
    if s[i] == "(":
        l += 1
        if l == 0:
            t += i-e+1
    elif s[i] == ")":
        l -= 1
        if l == -1:
            e = i
if l != 0:
    print(-1)
else:
    print(t)
