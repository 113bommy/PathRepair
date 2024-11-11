n = input()
l = []
for i in n:
    if len(l) and  i == l[-1]:
        # print(1, i, l)
        del l[-1]
    else:

        l.append(i)
        # print(2, i, l)
print('Yes' if l == [] else 'No')
