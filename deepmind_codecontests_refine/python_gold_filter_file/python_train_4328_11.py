n=int(input())
arr = [tuple(map(int, input().split())) for i in range(n)]
sl, sr = (0,0)
for h in arr: sl+=h[0]; sr+=h[1]
mx, a, i = abs(sl-sr), -1, 0
for h in arr:
    si = abs((sl-h[0]+h[1]) - (sr-h[1]+h[0]))
    if si>mx: mx,a=si,i
    i+=1
print(a+1)