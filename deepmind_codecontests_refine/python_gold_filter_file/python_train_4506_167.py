from random import randint
for _ in range(int(input())):
    a, b, c = list(map(int, input().split()))
    thresh = max(c-a-b, b-a-c, a-b-c, 0)
    thresh_max = a+b+c
    print(randint(thresh+1, thresh_max-1))