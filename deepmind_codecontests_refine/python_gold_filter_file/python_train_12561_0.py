def main():
    n, a, b = map(int, input().split())
    arr = [0 for _ in range(n)]
    brr = [0 for _ in range(n)]
    for i in range(n):
        arr[i], brr[i] = map(int,input().split())

    p = [i for i in range(n)]
    p.sort(key=lambda x: arr[x]-brr[x], reverse=True)
    total = 0
    for i in range(len(arr)):
        if i < b:
            total += max(arr[p[i]], brr[p[i]])
        else:
            total += brr[p[i]]

    if b == 0:
        print(total)
        return

    s = total
    pp = 1 << a
    for i in range(n):
        ctotal = s
        if i < b:
            ctotal -= max(arr[p[i]], brr[p[i]])
            ctotal += arr[p[i]] * pp
        else:
            ctotal -= brr[p[i]]
            ctotal += arr[p[i]] * pp
            ctotal -= max(arr[p[b-1]], brr[p[b-1]])
            ctotal += brr[p[b-1]]
        total = max(total, ctotal)

    print(total)


main()