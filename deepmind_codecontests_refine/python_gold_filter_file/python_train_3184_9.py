ts, tf, te = map(int, input().split(' '))
n = int(input())
if n == 0:
  print(ts)
  exit(0)
arr = list(map(int, input().split(' ')))
idx = 0
curr_time = ts
wait_time = max(0, ts-arr[0]+1)
ans = min(arr[0]-1, ts)

while wait_time > 0:
  curr_time+=te
  idx += 1
  if idx == n or curr_time >= tf:
    break
  next_wait = max(0, curr_time-arr[idx]+1)
  if next_wait < wait_time:
    wait_time = next_wait
    ans = arr[idx]-1

if wait_time > 0 and curr_time+te <= tf:
  ans = curr_time 

print(ans) #answer is guaranteed
