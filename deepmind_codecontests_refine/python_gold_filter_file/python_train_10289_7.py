s = input()
# print(s[:-1])
if len(s) != 26:
    for c in range(ord('a'), ord('z')+1):
        c = chr(c)
        if not c in s:
            print(s+c)
            exit()
s = list(s)
t = []
while s:
    for c in t:
        if c > s[-1]:
            print(''.join(s[:-1])+c)
            exit()
    t.append(s.pop())

print('-1')