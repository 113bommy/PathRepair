def arr_inp():
    return [int(x) for x in input().split()]


a = arr_inp()
a.sort()
ix, out = 0, sum(a)

while (ix < 5):
    a_copy = a.copy()
    c = a.count(a[ix])
    if (c >=2):
        for i in range(min(3,c)):
            a_copy.remove(a[ix])
        out=min(out,sum(a_copy))
    ix+=c
print(out)
