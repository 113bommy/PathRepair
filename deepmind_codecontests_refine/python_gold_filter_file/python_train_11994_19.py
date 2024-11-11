
n = int(input())
def re(l,r):
    if 'a' != l and 'a' != r :return 'a'
    if 'b' != l and 'b' != r: return 'b'
    if 'c' != l and 'c' != r: return 'c'
for _ in range(n):
    s = list(input())
    ln = len(s)
    sig=True
    if s[0]=='?':
        if ln == 1 : print('a');continue

        else:
            if s[1]=='a':s[0]='b'
            else:s[0]='a'
    else:
        if ln != 1 and s[0]==s[1]:print('-1');continue

    for i in range(1,ln-1):
        if s[i]=='?':s[i] = re(s[i-1],s[i+1])
        if s[i]==s[i+1]:print('-1');sig = False;break
    if sig:
        if s[ln - 1] == '?':
            if s[ln - 2] == 'a':
                s[ln - 1] = 'b'
            else:
                s[ln - 1] = 'a'
        # print(s)
        x = ''.join(s)
        print(x)

