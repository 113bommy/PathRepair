n = int(input())
color = "ROYGBIV"
leftC = "GBI"

mod = n % 7
if mod <= 2:left = leftC[:n % 7]
elif mod == 6: left = "GBIVGB"
elif mod == 3: left = "GBI"
elif mod == 4: left = "GBIV"
elif mod == 5: left = "GBIVG"


print(color*(n//7) + left)