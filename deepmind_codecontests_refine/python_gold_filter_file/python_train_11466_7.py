n = int(input())
a = []
set = set()
pairs = 0
dict = {}
for s in range(n):
    skobki = 0
    c = input()
    open = False
    open_reverse = False
    tmp = 0
    for i in range(len(c)):
        if c[i] == ")":
            skobki -= 1
            if open and tmp > 0:
                tmp -= 1
            elif open and tmp == 0:
                open = False
            else:
                open_reverse = True
        else:
            if open == True:
                tmp += 1
            else:
                open = True
            skobki += 1
    if open_reverse and open:
        pass
    else:
        a.append(skobki)

for elem in a:
    if -elem in set:
        pairs += 1
        if dict.get(-elem, 1) > 1:
            dict[-elem] = dict.get(-elem, 1) - 1
        else:
            set.discard(-elem)
    elif elem in set:
        dict[elem] = dict.get(elem, 1) + 1
    else:
        set.add(elem)

print(pairs)






