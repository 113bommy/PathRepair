v1, v2, v3, v4 = map(int, input().split())

def find_car_size():
  if (v3 > v4 and v3 > 2*v4) or (v4 > v3 and v4 > v3*2):
    return None
  sons = min(v3, v4)*2
  minimum_mom = v4*2+1
  if v2 <= v4:
    return None
  moms = max(minimum_mom, v2)
  fathers = max(moms+1, v1)
  return [fathers, moms, sons]

res = find_car_size()
if not res:
  print(-1)
else:
  for i in range(3):
    print(res[i])
