from itertools import combinations as f
L, R = map(int, input().split())

s = set(map(lambda x:x%2019, range(L, R+1)[:2019]))

print(min([i*j%2019 for i, j in f(s, 2)]))
