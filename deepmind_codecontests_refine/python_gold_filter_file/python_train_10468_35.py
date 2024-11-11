p = input()
if p in ['a8', 'h8', 'a1', 'h1']: print(3)
elif (('a' in p or 'h' in p) or ('1' in p or '8' in p)) and p not in ['a8', 'h8', 'a1', 'h1']: print(5)
else: print(8)
