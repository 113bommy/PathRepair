s = input()
print('yes' if len(list(s)) == len(set(s)) else 'no')