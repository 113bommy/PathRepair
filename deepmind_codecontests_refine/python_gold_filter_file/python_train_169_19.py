n =int(input())
s = input()
d = {}
for i in range(len(s)-1):
    if (s[i:i+2] in d):
        d[s[i:i+2]] += 1
    else:
        d[s[i:i+2]] = 1
print(max(d, key=d.get))