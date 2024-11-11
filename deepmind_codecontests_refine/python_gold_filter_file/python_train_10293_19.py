N, *a = map(int, open(0).read().split())
tgt = round(sum(a) / N)
print(sum((v - tgt) ** 2 for v in a))