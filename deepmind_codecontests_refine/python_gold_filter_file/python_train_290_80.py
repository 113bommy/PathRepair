n = int(input())
a = map(int, input().split())
print(sum(x-1 for x in a))
