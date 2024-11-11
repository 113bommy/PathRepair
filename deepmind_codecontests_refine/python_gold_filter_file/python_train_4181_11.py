d = {'s': 19, 'g': 7, 'y': 25, 'm': 13, 'b': 2, 'j': 10, 't': 20, 'c': 3, 'o': 15, 'x': 24, 'u': 21, 'l': 12, 'z': 26, 'e': 5, 'q': 17, 'k': 11, 'w': 23, 'n': 14, 'a': 1, 'd': 4, 'h': 8, 'i': 9, 'f': 6, 'v': 22, 'r': 18, 'p': 16}

from collections import Counter

n = int(input())
lst = []
for i in range(n):
    a = input()
    lst.append(a)


for i in lst:
    i_dict = dict(Counter(i))
#    print(i_dict)
    if not any(value > 1 for value in i_dict.values()):
        position_lst = []
        for k in i:
            position_lst.append(d[k])
        if max(position_lst) - min(position_lst) < len(position_lst):
            print('Yes')
        else:
            print('No')
    else:
        print('No')
        
