t = int(input())

for i in range(t):
    n = int(input())
    line = [int(x) % 3 for x in input().split()]

    three = line.count(0)
    one = line.count(1)
    two = line.count(2)

    m = min(one, two)

    three += m

    one -= m
    two -= m

    three += two // 3
    three += one // 3

    print(three )
