import bisect
while True:
    n = int(input())
    if n == 0:
        break
    score = []
    for _ in range(n):
        s = int(input())
        bisect.insort(score, s)
    print(sum(score[1:-1])//(len(score)-2))