x = int(input())
for i in range(x):
    s = input()
    y = s.count('ab')-s.count('ba')

    if abs(y)==2:
        if s[0]=='a':
            s = 'b' + s[1:]
        else:
            s = 'a' + s[1:]
        if s[len(s)-1] == 'a':
            s = s[:-1] + 'b'
        else:
            s = s[:-1] + 'a'

    if y==1:
        if s[:2]=='ab':
            s = 'b' + s[1:]
        else:
            s = s[:-1] + 'a'

    if y==-1:
        if s[:2]=='ba':
            s = 'a' + s[1:]
        else:
            s = s[:-1] + 'b'
    print(s)

