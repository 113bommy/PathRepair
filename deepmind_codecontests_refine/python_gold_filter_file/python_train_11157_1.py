q = int(input())

t = "RGB" * (2000 // 3 + 1)

for _ in range(q):
    n, k = map(int, input().split())

    s = input()

    mi = k
    for i in range(n - k + 1):
        subs = s[i:i + k]
        for j in range(3):
            subt = t[j:k + j]
            diff = 0
            for l in range(k):
                if subs[l] != subt[l]:
                    diff += 1
            # print(subs, subt, diff)
            mi = min(mi, diff)

    print(mi)
