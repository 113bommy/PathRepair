def get(a, b):
    return a*b


a = [int(x) for x in input().split()]
res = (a[0] + a[5]/2 + a[1]/2)*(a[5] + a[4])*2
res = res - get(a[1]/2, a[1]) - get(a[2]/2, a[2]) - get(a[4]/2, a[4]) - get(a[5]/2, a[5])
print(round(res))
