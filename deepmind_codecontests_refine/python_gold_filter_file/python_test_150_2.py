for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    l6 = all([x < 6 for x in l])
    b = 2e9
    for i in range(7):
        for j in range(4):
            for k in range(3):
                ok = [True, i > 0, i >= 2 or j >= 1,
                      k >= 1 or (i >= 1 and j >= 1) or (i >= 3),
                      (k >= 1 and i >= 1) or (j >= 2) or (j >= 1 and i >= 2) or
                      (i >= 4),
                      (k >= 1 and i >= 2) or (k >= 1 and j >= 1) or (j >= 2 and i >= 1)
                      or (j >= 1 and i >= 3) or (i >= 5), i + 2 * j + 3 * k == 6]
                if i + 2 * j + 3 * k > 6:
                    continue
                s = i + j + k
                if l6:
                    if any([not ok[x] for x in l]):
                        continue
                    b = min(b, s)
                else:
                    no = False
                    m = 0
                    for x in l:
                        yes = False
                        for I in range(min(6, x), -1, -1):
                            if ok[I] and (x - I) % 3 == 0:
                                yes = True
                                m = max(m, (x - I) // 3)
                                break
                        if not yes:
                            no = True
                            break
                    if no:
                        continue
                    b = min(b, s + m)
    print(b)