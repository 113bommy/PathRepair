l = input()
print('Yes' if len(set(l)) == 2 and l.count(l[0]) == 2 else 'No')