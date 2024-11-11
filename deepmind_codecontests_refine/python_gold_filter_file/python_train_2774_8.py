import sys, math

#f = open('input/input_1', 'r')
f = sys.stdin

N, K = map(int, f.readline().split())
box_size = map(int, f.readline().split())

ans = -1
ans_cnt = 0
ans_type = 0

for i, b in enumerate(box_size):
  num_box = (N//b)
  if ans < num_box * b:
    ans = num_box * b
    ans_cnt = num_box
    ans_type = i+1

print(ans_type, ans_cnt)
