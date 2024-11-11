n = int(input())
s = input()
while len(s) > 4:
    print(s[0:2],end='-')
    s = s[2:]
if len(s) <= 3:
    print(s)
else:
    print(s[0:2],s[2:4],sep = '-')