n = int(input())
print(sum(sorted([int(x) for x in input().split()] * 2, reverse = True)[1:n]))