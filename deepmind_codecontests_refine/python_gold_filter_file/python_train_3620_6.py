INF = 2000000000


def calc_xx(A, B, mult, comp_field, diff_field):
    AA = list(sorted(A, key=lambda pp: (pp[comp_field], pp[diff_field])))
    BB = list(sorted(B, key=lambda pp: (pp[comp_field], pp[diff_field])))

    a = 0
    b = 0

    min_time = INF
    while a < len(A) and b < len(B):
        # 衝突判定 (ソートの重複値の全組み合わせで検証)
        if AA[a][comp_field] == BB[b][comp_field]:
            astart = a
            asame = a + 1
            while asame < len(A) and AA[asame][comp_field] == AA[a][comp_field]:
                asame += 1
            aend = asame - 1

            bstart = b
            bsame = b + 1
            while bsame < len(B) and BB[bsame][comp_field] == BB[b][comp_field]:
                bsame += 1
            bend = bsame - 1

            # まさかの二重DP
            aa = astart
            bb = bstart
            while aa <= aend and bb <= bend:
                diff = BB[bb][diff_field] - AA[aa][diff_field]
                if diff > 0:
                    hit_time = diff * mult
                    min_time = min(min_time, hit_time)

                if aa == aend:
                    bb += 1
                elif bb == bend:
                    aa += 1
                elif BB[bb][diff_field] > AA[aa][diff_field]:
                    aa += 1
                else:
                    bb += 1

            a = aend + 1
            b = bend + 1

        elif a == len(A) - 1:
            b += 1
        elif b == len(B) - 1:
            a += 1
        elif AA[a][comp_field] > BB[b][comp_field]:
            b += 1
        elif AA[a][comp_field] < BB[b][comp_field]:
            a += 1
        else:
            raise Exception

    return min_time


def main():
    N = int(input())
    PLANES = []

    U = []
    R = []
    D = []
    L = []
    for i in range(N):
        # x=c[0]
        # y=c[1]
        # u=c[2]
        p = input().split()
        p[0] = int(p[0])
        p[1] = int(p[1])

        pp = [p[0], p[1], (p[0] + p[1]), (p[1] - p[0])]

        PLANES.append(p)
        if p[2] == "U":
            U.append(pp)
        elif p[2] == "R":
            R.append(pp)
        elif p[2] == "D":
            D.append(pp)
        else:
            L.append(pp)

    min_time = min(
        calc_xx(R, U, 10, 2, 0),
        calc_xx(U, D, 5, 0, 1),
        calc_xx(U, L, 10, 3, 0),
        calc_xx(R, D, 10, 3, 0),
        calc_xx(R, L, 5, 1, 0),
        calc_xx(D, L, 10, 2, 0),
    )

    if min_time == INF:
        print("SAFE")
    else:
        print(min_time)


main()
