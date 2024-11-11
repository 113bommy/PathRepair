
s = list(input())
n = len(s)
strat , end = -1 , -1

for i in range(n):
    if s[i] > 'a' and strat == -1:
        strat = i

    elif s[i] == 'a' and strat != -1:
        end = i
        break

#print(strat , end)

if end == -1:
    end = n

if strat == -1:
    s[n - 1] = 'z'
    print(''.join(s))

else:
    for i in range(strat , end):
        x = ord(s[i]) - 1
        s[i] = chr(x)

    print(''.join(s))