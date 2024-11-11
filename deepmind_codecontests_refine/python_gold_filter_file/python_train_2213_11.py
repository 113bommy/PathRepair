n, m = map(int, input().split())
x, k, y = map(int, input().split())
pref = (x - 1) // k + 1 <= y
a = list(map(int, input().split()))
a.append(0)
b = list(map(int, input().split()))
b.append(0)

i, i_prev = -1, -1
ans = 0
for el in b:

    i_prev = i
    try:
        i = a.index(el, i + 1)
    except ValueError:
        ans = -1
        break
    di = i - i_prev - 1

    if di:
        if pref:
            if a[i_prev] < max(a[i_prev + 1: i]) > a[i] and di < k:
                ans = -1
                break
            ans += x * (di // k) + y * (di % k)
        else:
            if a[i_prev] < max(a[i_prev + 1: i]) > a[i]:
                if di < k:
                    ans = -1
                    break
                ans += x + y * (di - k)
            else:
                ans += y * di
print(ans)