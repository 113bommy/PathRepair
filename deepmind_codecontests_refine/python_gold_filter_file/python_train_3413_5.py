x, y, a, b, c = map(int, input().split())
p = sorted(list(map(int, input().split())))[a-x:]
q = sorted(list(map(int, input().split())))[b-y:]
r = sorted(list(map(int, input().split()))+p+q)[::-1]

print(sum(r[:x+y]))
