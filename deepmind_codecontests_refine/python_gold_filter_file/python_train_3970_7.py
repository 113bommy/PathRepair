n = int(input())
a = []
fe = -1
se = -1
for i in range(2*n - 2):
    s = input()
    if len(s) == n - 1:
        if fe == -1:
            fe = i
        else:
            se = i
    a.append(s)
fl = True
s = a[fe] + a[se][-1]
b = [''] * len(a)
pr = [False] * n
su = [False] * n
for i in range(len(a)):
    #pr
    flp = False
    ss = a[i]
    if not pr[len(ss) - 1]:
        if s[:len(ss)] == ss:
            b[i] = 'P'
            pr[len(ss) - 1] = True
            flp = True
    if not flp:
        if not su[-len(ss)]:
            if s[-len(ss):] == ss:
                b[i] = 'S'
                su[-len(ss)] = True
                flp = True
    if not flp:
        fl = False
        break
if not fl:
    s = a[se] + a[fe][-1]
    pr = [False] * n
    su = [False] * n
    for i in range(len(a)):
        #pr
        flp = False
        ss = a[i]
        if not pr[len(ss) - 1]:
            if s[:len(ss)] == ss:
                b[i] = 'P'
                pr[len(ss) - 1] = True
                flp = True
        if not flp:
            if not su[-len(ss)]:
                if s[-len(ss):] == ss:
                    b[i] = 'S'
                    su[-len(ss)] = True
                    flp = True
for i in b:
    print(i, end = '')
                
            
