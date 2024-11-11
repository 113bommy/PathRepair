#!/usr/bin/env python


def main():
    n, a, b = map(int, input().split())
    health = [0]
    health.extend(map(int, input().split()))
    target = [0] * len(health)

    def need(t, d):
        nonlocal health
        p = health[t]
        return (p // d + 1) if p >= 0 else 0

    least_target = []
    least_thrown = sum(health)
    last_need = max(need(n - 1, a), need(n, b))

    def beat(left, sofar):
        nonlocal health, target, n, a, b, need
        nonlocal least_thrown, least_target, last_need

        if sofar >= least_thrown:
            return

        center = left + 1
        right = center + 1

        if right == n:
            m = max(need(left, b), last_need)
            thrown = sofar + m
            if thrown < least_thrown:
                least_thrown = thrown
                least_target = target[:]
                least_target[center] += m
            return

        must = need(left, b)
        for m in range(must, max(must, need(center, a)) + 1):
            ma = m * a
            mb = m * b

            health[left] -= mb
            health[center] -= ma
            health[right] -= mb
            target[center] += m

            beat(center, sofar + m)

            target[center] -= m
            health[right] += mb
            health[center] += ma
            health[left] += mb

    beat(1, 0)

    def target_sequence(targets):
        for t, k in enumerate(targets):
            if k:
                s = str(t)
                yield from (s for _ in range(k))

    if least_target:
        print(least_thrown)
        print(" ".join(target_sequence(least_target)))
    else:
        print(0)
        print()


if __name__ == '__main__':
    main()
