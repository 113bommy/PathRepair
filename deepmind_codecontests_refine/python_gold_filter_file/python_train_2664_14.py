n = int(input())
colors = 'ROYGBIV'

four_distance = 'GBIVGB'
sev_color = n // 7
rem = n % 7

out = (sev_color * colors) + four_distance[:rem]
    
print(out)
