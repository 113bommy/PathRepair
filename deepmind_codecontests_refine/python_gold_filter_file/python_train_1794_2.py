
def main():
  N, M = map(int, input().split())
  L = [tuple(map(int, input().split())) for _ in range(N)]
  maxi = max(max(t) for t in L)+1
  mini, res = max((min(t), i) for i, t in enumerate(L))
  res = res, res
  BITMASK = (1 << M)
  while True:
    mid = (maxi+mini)//2
    #print(f'{mini} {mid} {maxi}')
    if mid == mini:
      break
    masks = [None]*BITMASK
    for i, t in enumerate(L):
      tmask = 0
      for v in t:
        tmask *= 2
        if v >= mid:
          tmask += 1
      if masks[tmask] is not None:
        continue
      masks[tmask] = i
      for k in range(BITMASK):
        if masks[k] is not None and k | tmask == BITMASK-1:
          res = masks[k], i
          mini = mid = min(max(a, b) for a, b in zip(L[res[0]], L[res[1]]))
          break
      else:
        continue
      break
    else:
      maxi = mid
    #print(masks)
  print(res[0]+1, res[1]+1)


main()
