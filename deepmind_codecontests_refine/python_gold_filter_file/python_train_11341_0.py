#!/usr/bin/python3
# coding: utf-8

MAX_V = 100

# デバッグ用の関数
def show(origami):
    for i in range(MAX_V):
        for j in range(MAX_V):
            print(origami[i][j], end = " ")
        print()
    print("--------------------------------------")

# 右に c だけ折り返す処理
def fold_a(origami, c):
    t = c
    for i in range(c):
        for j in range(MAX_V):
            origami[j][t+i] += origami[j][t-i-1]
            origami[j][t-i-1] = 0

    copy = [x[:] for x in origami]

    for i in range(MAX_V):
        for j in range(MAX_V):
            if j-c < 0 or MAX_V-1 < j-c:
                continue
            origami[i][j-c] = copy[i][j]


# 上に c だけ折り返す処理
def fold_b(origami, c):
    t = MAX_V - c -1
    for i in range(MAX_V):
        for j in range(c):
            origami[t-j][i] += origami[t+j+1][i]
            origami[t+j+1][i] = 0

    copy = [x[:] for x in origami]

    for i in range(MAX_V):
        for j in range(MAX_V):
            if i+c < 0 or MAX_V-1 < i+c:
                continue
            origami[i+c][j] = copy[i][j]



def main():
    while True:
        n, m, t, p = map(int, input().split())

        origami = [[0 for i in range(MAX_V)] for _ in range(MAX_V)]

        for i in range(n):
            for j in range(m):
                origami[-1-j][i] = 1

        if n == 0 and m == 0 and t == 0 and p == 0:
            break

        for _ in range(t):
            d, c = map(int, input().split())

            if d == 1:
                fold_a(origami, c)
            if d == 2:
                fold_b(origami, c)

        for _ in range(p):
            x, y = map(int, input().split())
            print(origami[MAX_V-y-1][x])

    return 0

main()
