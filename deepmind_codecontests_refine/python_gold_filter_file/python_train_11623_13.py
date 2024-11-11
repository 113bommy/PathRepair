def likes(v, i):
    return v <= i and 2*v >= i


v1, v2, v3, vm = [int(i) for i in input().split()]

#if min([v1, v2, v3, vm]) != vm:
#    print("-1")
#    exit()
#else:
for i in range(201):
    for j in range(i):
        for k in range(j):
            if likes(v1, i) and likes(v2, j) and likes(v3, k) and likes(vm, k) and not likes(vm, j) and not likes(vm, i):
                print("%s\n%s\n%s" % (i, j, k))
                exit()
print("-1")