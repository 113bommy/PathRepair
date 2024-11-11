def main():
    n = int(input())
    a = input()
    b = input()
    ret = (n%2) and (a[n//2] != b[n//2])
    for i in range(n // 2):
        temp = set((a[i], a[n - 1 - i], b[i], b[n - 1 - i]))
        if len(temp) == 1:
            continue
        elif len(temp) == 2:
            ret += [a[i], a[n - 1 - i], b[i], b[n - 1 - i]].count(a[i]) != 2
        elif len(temp) == 3:
            ret += 1 + (a[i] == a[n - 1 - i])
        else:
            ret += 2
    print(ret + 0)
    return 0
main()