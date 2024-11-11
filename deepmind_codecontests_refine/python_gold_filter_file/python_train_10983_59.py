s = input()
b = 0
for i in s:
    if ord(i) <= 90:
        b += 1
if b > len(s)/2:
    print(s.upper())
else:
    print(s.lower())
