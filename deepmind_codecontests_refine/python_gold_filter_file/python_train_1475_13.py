def main():
    x = input()
    contests = list(map(int, input().split()))
    contests.sort()
    count = 0
    for i in range(len(contests)):
        if count + 1 <= contests[i]:
            count += 1
    print(count)


main()
