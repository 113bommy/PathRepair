n = int(input())
def getOther(x, y):
    if x == 'a':
        if y != 'b':
            return 'b'
        else:
            return 'c'
    elif x == 'b':
        if y != 'a':
            return 'a'
        else:
            return 'c'
    else:
        if y != 'a':
            return 'a'
        else:
            return 'b'

def getAns(s):
    curr = ''
    for x in s:
        if x == curr and x != '?':
            print(-1)
            return
        curr = x
    
    if len(s) == 1:
        if s[0] == "?":
            print("a")
            return
        else:
            print(s[0])
            return

    if s[0] == "?":
        if s[1] != "a":
            s[0] = "a"
        else:
            s[0] = "b"

    for x in range(1, len(s) - 1):
        if s[x] == "?":
            if s[x+1] == "?":
                if s[x-1] == "a":
                    s[x] = "b"
                else:
                    s[x] = "a"
            else:
                s[x] = getOther(s[x+1],s[x-1])
    
    if s[-1] == "?":
        if (s[-2] == "a"):
            s[-1] = "b"
        else:
            s[-1] = "a"

    print(''.join(s))
for i in range(n):
    getAns(list(input()))
