_, *a = map(int, open(0).read().split())
s = sorted(a)
for i in a:
    print(s[(i < s[-1])-2])