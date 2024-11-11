s = list(input())
t = list(input())

length = min(len(s), len(t))
c = length
for i in range(length):
    if s[len(s)-i-1] != t[len(t)-i-1]:
        #print(i, s[len(s)-i-1], t[len(t)-i-1])
        c = i
        break

print(len(s)-c+len(t)-c)