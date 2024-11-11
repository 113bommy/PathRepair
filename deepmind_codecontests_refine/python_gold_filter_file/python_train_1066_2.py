for t in range(int(input())):
  n, x, m = map(int, input().split())
  start = stop = x
  for i in range(m):
    # print("Start, Stop", start, stop)
    l, r = map(int, input().split())
    if start <= r and start > l:
      start = l
      if stop < r:
        stop = r
    elif stop >= l and not r < start:
      if stop < r:
        stop = r
      if start > l:
        start = l
        
  # print("Start, Stop", start, stop)
  print(stop - start + 1)
