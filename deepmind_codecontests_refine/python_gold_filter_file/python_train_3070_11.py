s = input()
t = input()

is_impossible = False

res = []
count = 0

for i in range(len(s)):
    if s[i] != t[i]:
        count += 1
        if count % 2 == 1:
            is_impossible = True
            res.append(s[i])
        else: 
            is_impossible = False
            res.append(t[i])
    else: 
        res.append(t[i])

if is_impossible:
    print('impossible')
else:
    print(''.join(res))
