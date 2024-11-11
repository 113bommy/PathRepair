_, *a = map(int, open(0).read().split())
odd = sum(ai % 2 for ai in a)
print('YNEOS'[odd % 2::2])