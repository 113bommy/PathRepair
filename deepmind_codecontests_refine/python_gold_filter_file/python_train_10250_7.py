

def main():
    n, k = map(int, input().split())
    s = input()
    counts = dict()

    for i in s:
        if i in counts:
            counts[i] += 1
        else:
            counts[i] = 1

    counts = list(counts.items())
    counts.sort(key= lambda x: x[1])

    ans = 0
    for a, v in reversed(counts):
        if v <= k:
            ans += v ** 2
            k -= v
        elif v > k:
            ans += k * k
            break

    print(ans)

main()