input()
lis = sorted(list(map(int, input().split())), reverse=True)
print(sum(lis[0::2]) - sum(lis[1::2]))