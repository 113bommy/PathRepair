t= int(input())
for tc in range(t):
    n, k = map(int, input().split())
    w = input()
    a = list(w)

    for r in range(k):
        o = z = q = 0
        for i in range(r, n, k):
            o += 1 if w[i] == "1" else 0
            z += 1 if w[i] == "0" else 0
            q += 1 if w[i] == "?" else 0
            
            if w[i] != "?":
                a[i % k] = w[i]
        if o > 0 and z > 0:
            print("NO")
            break
    else:
        o = 0
        q = 0

        for i in range(k):
            o += 1 if a[i] == "1" else 0
            q += 1 if a[i] == "?" else 0

        if o <= k//2 and o+q >= k//2:
            print("YES")
        else:
            print("NO")