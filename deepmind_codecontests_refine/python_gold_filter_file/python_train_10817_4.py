import statistics

while True:
    n = int(input())
    if n == 0: break
    s = [int(input()) for i in range(n)]
    ave = statistics.mean(sorted(s)[1:-1])
    print(int(ave))