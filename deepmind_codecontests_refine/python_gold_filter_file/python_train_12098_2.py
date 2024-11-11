for _ in range(int(input())):
    n, s = int(input()), {0}

    for d in range(1,n+1):
        if n//d in s: break
        s.update((d, n//d))
    print(len(s))
    print(' '.join(str(i) for i in sorted(s)))
