def insertion_sort(A, n, g, count):
    for i in range(g, n):
        v = A[i]
        j = i - g

        while(j>=0 and A[j] > v):
            A[j+g] = A[j]
            j = j - g
            count += 1

        A[j+g] = v

    return count

def shell_sort(A, n):
    count = 0
    g = 1
    G = []

    while g <= n:
        G.insert(0, g)
        g = g*3 + 1

    print(len(G))
    print(' '.join(map(str, G)))

    for i in range(len(G)):
        count = insertion_sort(A, n, G[i], count)

    print(count)
    print('\n'.join(map(str, A)))

if __name__ == '__main__':
    n = int(input())
    A = [int(input()) for i in range(n)]

    shell_sort(A, n)