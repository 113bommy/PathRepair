__author__ = "runekri3"

n = int(input())
weights = list(map(int, input().split()))

count_100 = weights.count(100)
count_200 = weights.count(200)

if count_200 % 2 == 0:
    if count_100 % 2 == 0:
        print("YES")
    else:
        print("NO")
else:
    if count_100 % 2 == 0 and count_100 >= 2:
        print("YES")
    else:
        print("NO")