n, *aa = map(int, open(0).read().split())

ranks = [a//400 for a in aa]

optional = [a for a in ranks if a>7]

ordinal = {a for a in ranks if a<=7}

print(max(1, len(ordinal)), len(ordinal)+len(optional))