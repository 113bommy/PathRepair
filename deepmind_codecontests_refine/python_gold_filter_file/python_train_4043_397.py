A, B, X = [int(x) for x in input().split()]
print('YNEOS'[1-(A<=X<=A+B-1)::2])
