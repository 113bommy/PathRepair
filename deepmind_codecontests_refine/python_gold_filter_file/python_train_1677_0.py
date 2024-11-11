s = input()

l = []
for i in range(1, len(s)+1):
    if s[0] == 'b':
        if i == len(s) or s[i-1] == 'a' and s[i] == 'b':
            l.append(1)
            s = s[:i][::-1] + s[i:]
        else:
            l.append(0)
    else:
        if i < len(s) and s[i-1] == 'b' and s[i] == 'a':
            l.append(1)
            s = s[:i][::-1] + s[i:]
        else:
            l.append(0)

for x in l:
    print(x, end=' ')
print()
        
        
