def decode(s, n):
    a = ""
    for i in s:
        if i.islower():
            o = ord(i) + n
            if o <= 122:
                a += chr(o)
            else:
                a += chr(o - 26)
        else:
            a += i
    return a

def judge(s):
    a = s.split()
    return "the" in a or "this" in a or "that" in a

while True:
    try:
        s = input()
    except:
        break
    for i in range(26):
        a = decode(s, i)
        if judge(a):
            print(a)
            break