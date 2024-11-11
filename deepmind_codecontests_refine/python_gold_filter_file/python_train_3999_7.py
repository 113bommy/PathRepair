def solve(a):
    ret = 1
    for i in range(len(a) - 1):
        if a[i] != a[i+1]:
            ret += 1
    return ret

print(solve([input()[0] for _ in range(int(input()))]))