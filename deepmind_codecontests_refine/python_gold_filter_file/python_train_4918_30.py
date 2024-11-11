for _ in range(int(input())):
    n,a,b = map(int, input().split())
    dic = list(map(chr, range(ord('a'), ord('z')+1)))
    answer = []

    for i in range(n):
        answer.append(dic[i%b])

    print(''.join(answer))
