hours, minutes = map(int, input().split())
h, d, c, n = map(float, input().split())


ans = 1000000000000000
for i in range(1440):
    if i < 60 * hours + minutes:
        continue
    dop_time = 60 * hours + minutes - i
    dop_value = dop_time * d
    golod = h + d*(i - 60 * hours - minutes)
    t = golod // n 
    if golod >  t * n  :
        t += 1
    money = t * c
    if i >= 60*20:
        money *= 0.8
        
    ans = min(ans, money)

print(ans)
    
