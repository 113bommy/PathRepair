s = input()
t = input()
D = {}

for i in range(0,len(s)):
    if s[i] != t[i]:
        D[i] = 1

if len(D)%2 == 1:
    print('impossible')
else:
    count = 1
    for i in range(0,len(s)):
        if i in D:
            if count <= len(D)//2:
                print(s[i], end = '')
                count += 1
            else:
                print(t[i], end = '')
        else:
            print(s[i], end = '')
        