# 12/25 AC日記
# GCDについて,2,3を追加しておくと全体のgcdは必ず1
# つまり残りは2の倍数または3の倍数を入れることにする?
# 2,3,a ではaは素数ではない.また3,(2+a)=3なのでa = 4?と思うが(3+a)は偶数なので7とする?
# 2,3,7に加えるとしたら？->この方法だと20000個数も取れないでしょ
# ちょっと難しいので休憩

# 12/27 再開
# 素因数は必ず2種類あるべきなのではないか
# それを2,3とする
# 0(mod2) ∧ !0(mod3) -> 総和は3の倍数
# 全部入れると丁度2万個なのでこれが想定されていそう
n = int(input())
nn = n
if n == 3:
    print("2 5 63")
else:
    res = [2, 4, 3, 9]
    n -= 4
    for i in range(2, 5001):
        if n < 2:
            break
        else:
            n -= 2
            res.append(6 * i - 4)
            res.append(6 * i - 2)
    for i in range(3, 5000, 2):
        if n < 2:
            break
        else:
            n -= 2
            res.append(6 * i - 3)
            res.append(6 * i + 3)
    for i in range(1, 5001):
        if n == 0:
            break
        else:
            n -= 1
            res.append(6 * i)
    for i in range(len(res)):
        print(str(res[i]) + " ", end="")