n = int(input())
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
s1 = input()
s2 = input()
a = inp(s1)
b = inp(s2)
a = a[1:]
b = b[1:]
p = [a]
q = [b]
i = 0
while len(a) != 0 and len(b) != 0:
    
    if a[0] > b[0]:
        x = a[0]
        y = b[0]
        a = a[1:]
        b = b[1:]
        a.append(y)
        a.append(x)
    else:
        x = a[0]
        y = b[0]
        a = a[1:]
        b = b[1:]
        b.append(x)
        b.append(y)
    i = i + 1
    if a in p and b in q:
        i = -1
        break
    p.append(a)
    q.append(b)

print (str(i)+" ", end = "")

if len(a) == 0:
    print (2)
elif len(b) == 0:
    print (1)
