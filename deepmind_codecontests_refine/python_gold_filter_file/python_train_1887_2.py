def calc(am, con):
    ans = am
    for i in range(len(con)):
        if am % 2 != 0:
            if con[i] >= am and i != 0:
                ans += am
            return ans
        if i == 0:
            am //=2
            continue
        if con[i] >= am:
            ans += am
            am //=2
        else:
            return ans
    return ans


def main():
    n = int(input())
    l = list(map(int, input().split()))
    dic = dict()
    for i in range(n):
        dic[l[i]] = 0
    for i in range(n):
        dic[l[i]] += 1
    l = list(dic.values())
    l.sort(reverse=True)
    ans = [0] * (l[0] + 1)

    for i in range(1, l[0] + 1):
        ans[i] = calc(i, l)
    print(max(ans))
main()