n = int(input())
i = list(map(int, input().split()))
i.sort(reverse=True)
print(sum(i[0::2])-sum(i[1::2]))