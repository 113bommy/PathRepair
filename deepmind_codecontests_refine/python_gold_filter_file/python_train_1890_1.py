t = input()
done=False
removed = t.replace('a', '')
s = removed[len(removed)//2:]
if s*2==removed and s==t[len(t)-len(s):]:
    print(t[:len(t)-len(s)])
else:
    print(':(')