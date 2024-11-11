import math
k = input()
s = input()

q = "qwertyuiopasdfghjkl;zxcvbnm,./"

s = list(s)
for i in range(len(s)):
    if k == "L":
        s[i] = q[q.index(s[i])+1]
    elif k == "R":
        s[i] = q[q.index(s[i])-1]
print(''.join(list(map(str, s))))

