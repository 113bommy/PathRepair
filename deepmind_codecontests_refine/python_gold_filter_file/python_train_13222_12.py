cnt = 0


def insertion_sort(seq, n, g):
    global cnt
    for i in range(g, n):
        v = seq[i]
        j = i - g
        while j >= 0 and seq[j] > v:
            seq[j + g] = seq[j]
            j = j - g
            cnt = cnt + 1
        seq[j + g] = v


def shell_sort(seq, n):
    g = 1
    G = []
    while g <= n:
        G.append(g)
        g = 3 * g + 1
    print(len(G))
    print(' '.join(map(str, reversed(G))))

    for g in reversed(G):
        insertion_sort(seq, n, g)
    return seq

n = int(input())
a = [int(input()) for _ in range(n)]
ans = shell_sort(a, n)
print(cnt)
print('\n'.join(map(str, ans)))