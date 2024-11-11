t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = []

    b = set([i for i in range(n+1)])
    while True:
        ind = sorted(list(b-set(a)))[0]
        if ind == n:
            break
        if a[ind] == ind:
            break
        else:
            a[ind] = ind
            ans.append(ind+1)

    k = 0
    count = [0]*(n+1)

    for i in range(n):
        count[a[i]] += 1

    for i in range(n):
        if a[i] == i:
            continue

        if count[i] == 0:
            ans.append(i+1)
            count[a[i]] -= 1
            count[i] += 1
            a[i] = i
            k += 1

        else:
            num = list(b - set(a))
            num.sort(reverse = True)

            for j in range(i+1, n):
                if a[j] == i:
                    next = num.pop()
                    count[next] += 1
                    count[a[j]] -= 1
                    a[j] = next
                    k += 1
                    ans.append(j+1)

            if sorted(a[i:]) == a[i:]:
                break

            count[a[i]] -= 1
            count[i] += 1
            a[i] = i
            ans.append(i+1)
            k += 1


    print(len(ans))
    print(" ".join(map(str, ans)))
