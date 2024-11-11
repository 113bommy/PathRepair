import sys
def yes():
    print('YES')
def no():
    print('NO')
def isinc(string):
    t=list(string)
    if t==sorted(t):
        return True
    return False
def isdec(string):
    t=list(string)
    if t==sorted(t,reverse=True):
        return True
    return False

L='abcdefghijklmnopqrstuvwxyz'
for _ in range(int(input())):
    s=sys.stdin.readline().strip()

    if set(list(s))!=set(list(L[:len(s)])):
        no();continue
    y=s.index('a')
    if y==0:
        if isinc(s[1:]):
            yes(); continue
        else:
            no(); continue
    elif y==len(s)-1:
        if isdec(s[:-1]):
            yes(); continue
        else:no(); continue
    else:
        s1=s[:y]
        s2=s[(y+1):]
        if not isinc(s2):
            no(); continue
        if not isdec(s1):
            no(); continue
        yes(); continue
            
