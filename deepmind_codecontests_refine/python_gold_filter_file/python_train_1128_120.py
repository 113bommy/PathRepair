n = int(input())
a = [int(_) for _ in input().split()]

rate = len(set([ai // 400 for ai in a if ai < 3200]))
count_master = len([ai for ai in a if ai >= 3200])

print(max(rate, 1), rate + count_master)