chars = ['a','b','c']
ll = None

def findNext(c1,c2):
    global chars
    for i in range(3):
        if chars[i] != c1 and chars[i] != c2:
            return chars[i]

def changeL(i):
    global ll
    if i==0:
        if len(ll) > 1:
            ll[i] = findNext('z',ll[1])
        else:
            ll[i] = 'a'
    elif i==len(ll)-1:
        ll[i] = findNext('z',ll[-2])
    else:
        ll[i] = findNext(ll[i-1],ll[i+1])

for _ in range(int(input())):
    ll = list(input())    
    for i in range(len(ll)):
        c = ll[i]
        if c=='?':
            changeL(i)
    fail = False
    for i in range(len(ll)-1):
        if ll[i] == ll[i+1]:
            fail=True
            break
    if fail:
        print(-1)
    else:
        print(''.join(ll))    
    
    
    