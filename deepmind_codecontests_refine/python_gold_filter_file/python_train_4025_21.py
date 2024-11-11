import math

h, m = map(int, input().split())
H, D, C, N = map(int, input().split())

mins = h*60 + m
discount = 20*60

feed_now = math.ceil(H / N) * C
feed_discount = math.ceil((H + D * max(0, discount-mins))/ N) * C * 0.8

print(min(feed_now, feed_discount))
