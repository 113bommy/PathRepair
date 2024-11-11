s = input()
c = 0

for i in s:
    if i.isupper():
        c += 1

if c > len(s) - c:
    print(s.upper())
else:
    print(s.lower())