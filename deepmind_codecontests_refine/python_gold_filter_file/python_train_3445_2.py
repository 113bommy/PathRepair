#!/usr/bin/python3

def pr(H, W, mtx, vec):
    for y in range(H):
        print(*[mtx[y][x] for x in range(W)], sep='', end=' ')
        print(vec[y])
    print()


def solveb(N, M, A, B, bit):
    mtx = [bytearray(N * M) for _ in range(N + M)]
    for m in range(M):
        for i in range(m, N * M, M):
            mtx[m][i] = 1

    for n in range(N):
        for i in range(M):
            mtx[M + n][n * M + i] = 1

    vec = bytearray(N + M)
    for m in range(M):
        vec[m] = (B[m] >> bit) & 1
    for n in range(N):
        vec[M + n] = (A[n] >> bit) & 1

    H = N + M
    W = N * M

    ox = 0
    bottomy = H
    for oy in range(H):
        # print(f'oy={oy} ox={ox}')
        # pr(H, W, mtx, vec)

        if ox == W:
            bottomy = oy
            break

        if mtx[oy][ox] == 0:
            while True:
                rep = False

                for y in range(oy + 1, H):
                    if mtx[y][ox] == 1:
                        row = mtx[oy]
                        mtx[oy] = mtx[y]
                        mtx[y] = row

                        v = vec[oy]
                        vec[oy] = vec[y]
                        vec[y] = v
                        break

                if mtx[oy][ox] == 0:
                    ox += 1
                    # print(f'ox={ox}')
                    if ox < W:
                        rep = True

                if not rep:
                    break

        if ox == W:
            bottomy = oy
            break

        for y in range(oy + 1, H):
            if mtx[y][ox] == 1:
                for x in range(ox, W):
                    mtx[y][x] ^= mtx[oy][x]
                vec[y] ^= vec[oy]

        ox += 1

    # print(f'bottomy={bottomy}')
    # pr(H, W, mtx, vec)

    for y in range(bottomy, H):
        if vec[y] == 1:
            return None

    for oy in range(bottomy - 1, -1, -1):
        ox = -1
        for x in range(0, W):
            if mtx[oy][x] == 1:
                ox = x
                break
        assert ox != -1

        # print(f'oy={oy} ox={ox}')
        # pr(H, W, mtx, vec)

        for y in range(oy):
            if mtx[y][ox] == 1:
                for x in range(W):
                    mtx[y][x] ^= mtx[oy][x]
                vec[y] ^= vec[oy]

    # pr(H, W, mtx, vec)

    ans = bytearray(N * M)
    for y in range(bottomy):
        ox = -1
        for x in range(W):
            if mtx[y][x] == 1:
                ox = x
                break
        assert ox != -1

        ans[ox] = vec[y]

    # print(f'ans={ans}')

    return ans


def solve(N, M, A, B):
    ans = [0] * (N * M)

    for bit in range(32):
        ansb = solveb(N, M, A, B, bit)

        if ansb is None:
            return None

        for i in range(N * M):
            ans[i] |= (ansb[i] << bit)

    result = [[0] * M for _ in range(N)]
    for y in range(N):
        for x in range(M):
            result[y][x] = ans[y * M + x]

    return result


def main():
    N, M = [int(e) for e in input().split(' ')]
    A = [int(e) for e in input().split(' ')]
    B = [int(e) for e in input().split(' ')]
    assert len(A) == N
    assert len(B) == M

    ans = solve(N, M, A, B)
    if ans is None:
        print('NO')
        return

    print('YES')
    for row in ans:
        print(*row)


if __name__ == '__main__':
    main()
