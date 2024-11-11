from bisect import bisect_right
def main():
    n = int(input())
    line = list(input())
    sor = [(line[0], 0)]
    ans = ['0']
    for i in range(1, n):
        j = bisect_right(sor, (line[i], 1))
        if j == len(sor):
            col = (sor[j - 1][1] + 1) % 2
        else:
            col = sor[j][1]
        k = j
        while k < len(sor) and col == sor[k][1]:
            k += 1
        if k != len(sor):
            print("NO")
            return 0
        sor.insert(j, (line[i], (col + 1) % 2))
        ans.append(str((col + 1) % 2))
    print("YES")
    print(''.join(ans))
main()