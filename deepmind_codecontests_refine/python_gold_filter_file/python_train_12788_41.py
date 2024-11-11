
A, B, C, D, E, F = map(int, input().split())

density = -1
ans = (0, 0)

for a in range(31):
  for b in range(31):
    for c in range(101):
      for d in range(101):
        water = 100*a*A + 100*b*B
        suger = c*C + d*D
         
        if water + suger > F or water == 0:
          break

        if (water / 100) * E >= suger:
        
          tmp = (100 * suger)  / (water + suger)

          if tmp > density:
            density = tmp
            ans = (water+suger, suger)

print(*ans)