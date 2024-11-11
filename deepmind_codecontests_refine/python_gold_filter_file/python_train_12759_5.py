t = input()
for i,c in enumerate(t):
    if c!='a':
        
        if 'a' in t[i:]:
            last_a = t[i:].index('a') + i
            print (t[:i] + ''.join(chr(ord(x)-1) for x in t[i:last_a]) + t[last_a:])
        else:
            print (t[:i] + ''.join(chr(ord(x)-1) for x in t[i:]))
        break
else:
    print (t[:-1] + 'z')