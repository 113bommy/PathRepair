def main():
    n = int(input())
    seq = [int(c) for c in input().split()]

    cnt = ans = 0
    for i in range(n):
        if cnt < 2:
            cnt += 1
        else:
            if seq[i] == seq[i-1] + seq[i-2]:
                cnt += 1
            else:
                cnt = 2

        ans = max(ans, cnt)

    print(ans)



if __name__ == "__main__":
    main()