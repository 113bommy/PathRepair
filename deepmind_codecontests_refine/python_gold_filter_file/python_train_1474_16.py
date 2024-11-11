n = int(input())

a = list(map(int, input().split()))

inc = [-1]
dec = [1e9]
ans = [0] * (n + 1)

for i in range(n):
    if a[i] > inc[-1] and a[i] < dec[-1]:
        if i == n - 1:
            inc.append(a[i])
        else:
            y = a[i + 1]
            if a[i] < y:
                inc.append(a[i])
            else:
                dec.append(a[i]);
                ans[i] = 1
    elif a[i] > inc[-1] and a[i] >= dec[-1]:
        inc.append(a[i])

    elif a[i] <= inc[-1] and a[i] < dec[-1]:
        dec.append(a[i])
        ans[i] = 1

    elif a[i] <= inc[-1] and a[i] >= dec[-1]:
        print("NO")
        exit(0)
print("YES")
print(*ans[0:n])