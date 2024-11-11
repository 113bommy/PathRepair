n = int(input())
nums = list(map(int, input().split()))

print('NO' if (sum(map(lambda x:x%2, nums)))%2 else 'YES')
