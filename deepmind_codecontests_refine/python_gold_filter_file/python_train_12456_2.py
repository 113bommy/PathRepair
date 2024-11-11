def main():
    N = int(input())
    F = tuple(map(int, input().split()))

    for i, b in enumerate(F):
        try:
            c = F.index(i+1) + 1
        except ValueError:
            continue
        if F[b-1] == c:
            print('YES')
            break
    else:
        print('NO')

main()
