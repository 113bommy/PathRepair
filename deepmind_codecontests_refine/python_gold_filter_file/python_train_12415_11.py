import time

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    counts = [0 for _ in range(n+1)]
    for i in range(n):
        counts[a[i]] += 1

    k = 0
    idx = []
    while True:
        i = 0
        while counts[i] != 0:
            i += 1

        done = True
        if i == n:
            # Replace the first element in the wrong position
            for j in range(n):
                if a[j] != j:
                    k += 1
                    counts[a[j]] -= 1
                    a[j] = i
                    counts[i] += 1
                    done = False
                    idx.append(j+1)
                    break
        else:
            # Replace the idx at the relevant position
            k += 1
            counts[a[i]] -= 1
            a[i] = i
            counts[i] += 1
            done = False
            idx.append(i+1)

        if done:
            break
    print(k)
    print(' '.join(map(str, idx)))




