s = input()
a = []
for i in range(len(s)):
    if not(s[i] in a):
        a.append(s[i])
if len(a) % 2 == 1:
    print('IGNORE HIM!')
else:
    print('CHAT WITH HER!')