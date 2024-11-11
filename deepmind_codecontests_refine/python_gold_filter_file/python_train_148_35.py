def inp(s):
    j = 0
    a = []
    for i in range(len(s)):
        if s[i] == " ":
            a.append(int(s[j:i]))
            j = i+1
        if i == len(s)-1:
            a.append(int(s[j:]))
    return a

s = input()
a = inp(s)
r = 0
for i in a:
    r = r + i

if r == 0:
    print (-1)

elif r%5 == 0:
    print (int(r/5))
else:
    print (-1)