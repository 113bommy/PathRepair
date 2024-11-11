for _ in range(int(input())):
    n, length = map(int, input().split())
    arr = list(map(int, input().split()))
    a = [0.0]*n
    b = [0.0]*n
    a[0] = arr[0]
    b[-1] = length - arr[-1]
    sa = 2
    sb = 2
    for i in range(1, n):
        a[i] += (arr[i]-arr[i-1]) / sa + a[i-1]
        sa += 1
    for i in reversed(range(0, n-1)):
        b[i] += (arr[i+1] - arr[i]) / sb + b[i+1]
        sb += 1

    pos = -1
    for i in range(n):
        if a[i] >= b[i]:
            pos = i
            break
    if a[pos] == b[pos]:
        print(a[pos])
    else:
        if pos == 0:
            sa = 1
            sb = n-pos+1
            dist_a = sa*b[pos]
            time = b[pos]
            dist_b = arr[pos]
            y = (sa*dist_b + sb*dist_a)/(sa+sb)
            time += (y-dist_a) / sa
        elif pos == -1:
            sb = 1
            sa = n+1
            dist_b = length - sb*a[pos]
            dist_a = arr[pos]
            y = (sa*dist_b + sb*dist_a)/(sa+sb)
            time = (y-dist_a) / sa
            time += a[pos]
        else:
            if a[pos-1] < b[pos]:
                temp = b[pos] - a[pos-1]
                time = b[pos]
                dist_b = arr[pos]
                sb = n-pos+1
                sa = pos+1
                dist_a = sa*temp + arr[pos-1]
                y = (sa*dist_b + sb*dist_a)/(sa+sb)
                time += (y-dist_a)/sa
            else:
                temp = a[pos-1] - b[pos]
                time = a[pos-1]
                sb = n - pos + 1
                dist_b = arr[pos] - sb * temp
                sa = pos + 1
                dist_a = arr[pos - 1]
                y = (sa * dist_b + sb * dist_a) / (sa + sb)
                time += (dist_b - y) / sb
        print(time)
