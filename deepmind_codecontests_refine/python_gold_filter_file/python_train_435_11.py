def solve():
    a, b = input().split(" ")
    if a < b:
        return a
    a = list(a)
    mniejsze = [int()]*len(a)
    najmniejszy = len(a)-1
    for i in range(len(a)-1, -1, -1):
        mniejsze[i] = -1
        if a[najmniejszy] < a[i]:
            mniejsze[i] = najmniejszy
        if a[i] < a[najmniejszy]:
            najmniejszy = i

    for i in range(min(len(a), len(b))):
        if mniejsze[i] != -1 and a[mniejsze[i]] < b[i]:
            a[i], a[mniejsze[i]] = a[mniejsze[i]], a[i]
            return "".join(a)
        if mniejsze[i] != -1 and a[mniejsze[i]] == b[i]:
            a[i], a[mniejsze[i]] = a[mniejsze[i]], a[i]
            if "".join(a) < b:
                return "".join(a)
            a[i], a[mniejsze[i]] = a[mniejsze[i]], a[i]
        if a[i] > b[i]:
            break
    return "---"


n = int(input())
for i in range(n):
    print(solve())
