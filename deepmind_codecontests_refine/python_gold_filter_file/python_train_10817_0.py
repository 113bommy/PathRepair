while True:
    n = int(input())
    if n == 0:
        exit()
    score = []
    for i in range(n):
        score.append(int(input()))
    print(sum(sorted(score)[1:-1])//(n-2))