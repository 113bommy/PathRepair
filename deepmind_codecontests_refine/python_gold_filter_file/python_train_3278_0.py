n = input().strip()
ll = []
for i in range(16,1001,8):
    ll.append(str(i))
if '0' in n:
    print('YES\n0')
elif '8' in n:
    print('YES\n8')
else:
    f = False
    p = n
    for i in ll:
        n = p
        q = ''
        for j in range(len(i)):
            l = n.find(i[j])
            if l != -1:
                q += i[j]
                n = n[l+1:]
            else:
                break
        if len(q) == len(i):
            f = True
            print('YES\n'+q)
            break
    print('NO' if f == False else '')
