_, k, *x = map(int, open(0).read().split())
print(sum(i if k/2>i else k-i for i in x)*2)