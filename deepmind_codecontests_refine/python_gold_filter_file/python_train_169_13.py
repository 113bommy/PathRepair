n = int(input())
s = input()
a = dict()
a['MAX'] = -1
MAX = s[0:2]
for i in range(len(s)-1):
    pattern = s[i] + s[i+1]
    if pattern in a:
        a[pattern] += 1
        if a[pattern] > a['MAX']:
            MAX = pattern
            a['MAX'] = a[pattern]
    else:
        a[pattern] = 1
print (MAX)
