n = int(input()) +1

A = sum(map(int,input().split()))

print(sum((A + i) % n != 1 for i in range(1,6) ))


