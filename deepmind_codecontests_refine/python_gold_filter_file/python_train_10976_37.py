n, k = map(int, input().split())
past = [int(i) for i in input().split()]
able = [i for i in past if i + k <= 5]
ans = len(able) // 3
print(ans)